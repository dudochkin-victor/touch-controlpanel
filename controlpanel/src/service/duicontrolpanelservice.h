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

/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */

#ifndef DUICONTROLPANELSERVICE_H
#define DUICONTROLPANELSERVICE_H

#include <MApplicationService>
#include "pages.h"

class DuiControlPanelService: public MApplicationService
{
    Q_OBJECT
public:
    DuiControlPanelService();
    void createStartPage();

    static bool isStartedByServiceFw;

Q_SIGNALS:
    void closeAppletLaunchers ();

public Q_SLOTS:
    void launch ();
    void launch (const QStringList &parameters);
    bool appletPage(const QString& appletName);
    bool appletPage(const QStringList& params);
    void categoryPage(const QString& category);
    void mainPage();
    bool registerService ();
    bool unregisterService ();

private:
    void sheduleStart (const PageHandle &handle);
    void startPageForReal(const PageHandle &handle);
    void receiveCloseSignal ();

    // stores the startpage until the app is not started, after that it is 0
    PageHandle *m_StartPage;
    bool m_IsRegistered;
};


#endif

