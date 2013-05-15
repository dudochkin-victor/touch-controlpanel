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

#ifndef DCPAPPLETWIDGET_H
#define DCPAPPLETWIDGET_H

#include <QObject>
class DcpWidget;
class DcpStylableWidget;
class QGraphicsWidget;

/*!
 * This is a temporary container class which is used to hide the
 * differences between DcpWidget and DcpStylableWidget
 */
class DcpAppletWidget: public QObject
{
    Q_OBJECT
public:
    DcpAppletWidget(DcpWidget* widget, QObject * parent = 0);
    DcpAppletWidget(DcpStylableWidget* widget, QObject * parent = 0);

    ~DcpAppletWidget();

    void setReferer (int widgetId);
    bool back ();
    bool pagePans () const;
    int getWidgetId ();
    bool setWidgetId (int widgetId);
    QString title() const;
    bool isProgressIndicatorVisible () const;

    QGraphicsWidget* graphicsWidget () const;

public slots:
    void setProgressIndicatorVisible (bool visible);

signals:
    void changeWidget (int widgetId);
    bool activatePluginByName (const QString &appletName) const;
    void closePage();
    void inProgress (bool isInProgress);

private:
    DcpWidget* m_Widget;
    DcpStylableWidget* m_StylableWidget;
};


#endif // DCPAPPLETWIDGET_H

