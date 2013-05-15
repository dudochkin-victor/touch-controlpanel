/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#ifndef TESTAPPLET_H__
#define TESTAPPLET_H__

#include <DcpAppletIf>
#include <QObject>

class DcpWidget;

class TestApplet : public QObject, public DcpAppletIf
{
    Q_OBJECT
    Q_INTERFACES(DcpAppletIf)

    public:

    virtual ~TestApplet();

    virtual void init();
    virtual DcpWidget *constructWidget(int widgetId);
    virtual QString title() const;
    virtual QVector<MAction*> viewMenuItems();
    virtual DcpBrief *constructBrief(int);
};




#endif // TESTAPPLET_H__
