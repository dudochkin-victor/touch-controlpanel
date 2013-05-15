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

#ifndef SKELETONAPPLET_H
#define SKELETONAPPLET_H

#include <DcpAppletIf>
#include <QObject>
#include <QVector>
#include <MAction>
class DcpWidget;

class SkeletonApplet : public QObject, public DcpAppletIf
{
    Q_OBJECT
    Q_INTERFACES(DcpAppletIf)

public:
    virtual void init();
    virtual DcpWidget* constructWidget(int widgetId);

    virtual QVector<MAction*> viewMenuItems() { return QVector<MAction*>(); }

protected:
    DcpWidget* pageMain();
};

#endif // SKELETONAPPLET_H

