/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include "dcpremotebriefreceiver.h"
#include "dcpremotebriefreceiver_p.h"

#include <../../briefsupplier/src/bsuppliercommands.h>
#include <QCoreApplication>
#include <QTimer>
#include <dcpdebug.h>

// the millisec after which the connection trial will be retried on failure
static const int RETRY_TIME = 500;

DcpRemoteBriefReceiver* DcpRemoteBriefReceiverPriv::instance = 0;
bool DcpRemoteBriefReceiverPriv::disabled = false;
QStringList DcpRemoteBriefReceiverPriv::args;


DcpRemoteBriefReceiverPriv::DcpRemoteBriefReceiverPriv ():
    send (&socket),
    receive (&socket),
    currentBrief (0)
{
    send.setCodec("UTF-8");
    receive.setCodec("UTF-8");
}


DcpRemoteBriefReceiver::DcpRemoteBriefReceiver():
    priv (new DcpRemoteBriefReceiverPriv())
{
    connect (this, SIGNAL (started()), this, SLOT (onStarted()));
    connect (& priv->socket, SIGNAL (readyRead()), this, SLOT (onReadyRead()));
    connect (this, SIGNAL (finished (int, QProcess::ExitStatus)),
             this, SLOT (onFinished (int, QProcess::ExitStatus)));

    setProcessChannelMode (QProcess::ForwardedChannels);
    startProcess();

    connect (& priv->socket, SIGNAL (error (QLocalSocket::LocalSocketError)),
             this, SLOT (onConnectError ()));
    connect (& priv->socket, SIGNAL (connected ()),
             this, SLOT (onConnected ()));
}

DcpRemoteBriefReceiver::~DcpRemoteBriefReceiver()
{
    DcpRemoteBriefReceiverPriv::instance = 0;
    delete priv;
}

void
DcpRemoteBriefReceiver::startProcess ()
{
    start ("duicontrolpanel-briefsupplier", DcpRemoteBriefReceiverPriv::args);
}

void
DcpRemoteBriefReceiver::onConnected ()
{
    // runs all the commands which arrived when we were not connected:
    if (!priv->waitingCommands.isEmpty()) {
        foreach (QString command, priv->waitingCommands) {
            priv->send << command << endl;
        }
        priv->send.flush ();
        priv->socket.flush ();
        priv->waitingCommands.clear();
    } else {
        static bool firstTime = true;
        if (firstTime) {
            // this signal is used for determining when to preload
            // an applet launcher instance
            emit firstConnected ();
            firstTime = false;
        }
    }
}

/*
 * Sets the arguments which are passed to the helper process
 */
void DcpRemoteBriefReceiver::setArguments (int argc, char** argv)
{
    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            DcpRemoteBriefReceiverPriv::args << argv[i];
        }
    }
}

/*!
 * \brief Disables using the brief supplier process.
 *
 * Stops it if it is running, and disables starting it again.
 */
void DcpRemoteBriefReceiver::disable ()
{
    delete instance();
    DcpRemoteBriefReceiverPriv::disabled = true;
}


void DcpRemoteBriefReceiver::onStarted ()
{
    priv->socket.connectToServer (BSupplier::BServerId);
}

void DcpRemoteBriefReceiver::onConnectError ()
{
    // retry:
    QTimer::singleShot (RETRY_TIME, this, SLOT (onStarted ()));
    qWarning ("Error connecting to the helper process: %s, retry",
              qPrintable (priv->socket.errorString ()));
}

void DcpRemoteBriefReceiver::watch (DcpRemoteBrief* brief)
{
    QString appletName = brief->name();
    if (priv->briefs.contains (appletName)) {
        return;
    }
    priv->briefs.insert (appletName, brief);
    cmd (BSupplier::CmdWatch, appletName);
}

int DcpRemoteBriefReceiver::watchCount ()
{
    return priv->briefs.count();
}

void DcpRemoteBriefReceiver::unwatch(DcpRemoteBrief* brief)
{
    QString appletName = brief->name();
    if (!priv->briefs.contains (appletName)) return;

    priv->briefs.remove (appletName);
    cmd (BSupplier::CmdUnwatch, appletName);
}

void DcpRemoteBriefReceiver::switchToggle(const QString& appletName)
{
    cmd (BSupplier::CmdSwitchToggle, appletName);
}

void DcpRemoteBriefReceiver::setValue(const QString& appletName,
                                      const QVariant& value)
{
    cmd (BSupplier::CmdSetValue,
         appletName + BSupplier::ParamSeparator + value.toString());
}

void DcpRemoteBriefReceiver::cmd (
        const QString& command, const QString& appletName)
{
    if (priv->socket.state() == QLocalSocket::ConnectedState) {
        priv->send << command << appletName << endl;
        priv->send.flush ();
        priv->socket.flush ();
    } else {
        priv->waitingCommands.append (command + appletName);
    }
}

bool tryMatch (const QString& key, const QString& line, QString& argument)
{
    int cropSize = key.count();
    if (line.count() > cropSize) {
        if (line.at(cropSize) != '=') return false;
        cropSize++;
    }

    if (line.startsWith (key)) {
        argument = line.mid(cropSize);
        return true;
    }
    return false;
}

void DcpRemoteBriefReceiver::onReadyRead()
{
    QString line;
    do {
        line = priv->receive.readLine();
        if (line.isEmpty()) continue;
        QString arg;
        if (tryMatch (BSupplier::OutputBegin, line, arg)) {
            dcp_failfunc_unless (!priv->currentBrief);

        } else if (tryMatch (BSupplier::OutputEnd, line, arg)) {
            if (priv->currentBrief) {
                priv->currentBrief->emitChange();
            }
            priv->currentBrief = 0;

        } else if (tryMatch (BSupplier::OutputName, line, arg)) {
            dcp_failfunc_unless (!priv->currentBrief);
            priv->currentBrief = priv->briefs.value(arg);

        } else {
            if (!priv->currentBrief) {
                continue;
            }
            // this section handles the following keys:
            static const char* keys[] = {
                BSupplier::OutputWidgetTypeID,
                BSupplier::OutputValueText,
                BSupplier::OutputIcon,
                BSupplier::OutputToggle,
                BSupplier::OutputTitleText,
                BSupplier::OutputHelpId,
                BSupplier::OutputValue,
                BSupplier::OutputMinValue,
                BSupplier::OutputMaxValue,
                BSupplier::OutputValueStep
            };
            int keyCount = sizeof(keys)/sizeof(const char*);
            int i;
            for (i=0; i<keyCount; i++) {
                if (tryMatch (keys[i], line, arg)) {
                    dcp_failfunc_unless (priv->currentBrief);
                    priv->currentBrief->set (keys[i],arg);
                    break;
                }
            }
            if (i>=keyCount) {
                qFatal ("Communication protocol failure with brief supplier:"
                        "\n%s", qPrintable(line));
            }
        }
    } while (!line.isNull()); // XXX TODO exit gracefully
}

void DcpRemoteBriefReceiver::onFinished (
        int exitCode, QProcess::ExitStatus exitStatus )
{
    Q_UNUSED (exitCode);
    Q_UNUSED (exitStatus);

    if (exitStatus == QProcess::CrashExit) {
        // process crashed, we need to resend the watches to be in sync
        // (crash protection will ensure that the crashed applet wont be loaded
        // again)
        foreach (QString appletName, priv->briefs.keys()) {
            cmd (BSupplier::CmdWatch, appletName);
        }
        priv->currentBrief = 0;
        startProcess ();

    } else {
        DcpRemoteBriefReceiverPriv::instance = 0;
        this->deleteLater ();
    }
}

DcpRemoteBriefReceiver* DcpRemoteBriefReceiver::instance ()
{
    if (DcpRemoteBriefReceiverPriv::disabled) {
        return 0;
    }
    if (!DcpRemoteBriefReceiverPriv::instance) {
        DcpRemoteBriefReceiverPriv::instance = new DcpRemoteBriefReceiver ();
    }
    return DcpRemoteBriefReceiverPriv::instance;
}

void DcpRemoteBriefReceiver::destroy ()
{
    if (DcpRemoteBriefReceiverPriv::instance) {
        delete DcpRemoteBriefReceiverPriv::instance;
    }
}

