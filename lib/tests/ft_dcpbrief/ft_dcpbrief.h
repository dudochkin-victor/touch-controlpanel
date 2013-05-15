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

#ifndef FT_DCPBRIEF_H
#define FT_DCPBRIEF_H

#include <QtTest/QtTest>
#include <QObject>

// the real unit/DcpBrief class declaration
#include <dcpbrief.h>

Q_DECLARE_METATYPE(DcpBrief*);

class Ft_DcpBrief : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    void initTestCase();
    void cleanupTestCase();
    void testCreation();
    void testWidgetTypeID();
    void testValueText();
    void testIcon();
    void testToggleIconId();
    void testAlign();
    void testToggle();
    void testImage();
    void testActivate();
    void testTitleText();
    

private:
    DcpBrief* m_subject;
};

#endif
