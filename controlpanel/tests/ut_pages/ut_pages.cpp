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

#include <QObject>
#include <QGraphicsSceneMouseEvent>

#include <pages.h>


#include "ut_pages.h"

void Ut_PageHandle::init()
{
}

void Ut_PageHandle::cleanup()
{
}

void Ut_PageHandle::initTestCase()
{
}

void Ut_PageHandle::cleanupTestCase()
{
}

void Ut_PageHandle::testCreation()
{
    PageHandle h1(PageHandle::MAIN);
    QVERIFY(h1.id == PageHandle::MAIN);
    QVERIFY(h1.param == "");
    QVERIFY(h1.widgetId == -1);
    QVERIFY(!h1.isStandalone);
    
    PageHandle h2(PageHandle::MAIN, "param");
    QVERIFY(h2.id == PageHandle::MAIN);
    QVERIFY(h2.param == "param");
    QVERIFY(h2.widgetId == -1);
    QVERIFY(!h2.isStandalone);
    
    PageHandle h3(PageHandle::MAIN, "param", 1);
    QVERIFY(h3.id == PageHandle::MAIN);
    QVERIFY(h3.param == "param");
    QVERIFY(h3.widgetId == 1);
    QVERIFY(!h3.isStandalone);

    PageHandle h4(PageHandle::MAIN, "param", 1, true);
    QVERIFY(h4.id == PageHandle::MAIN);
    QVERIFY(h4.param == "param");
    QVERIFY(h4.widgetId == 1);
    QVERIFY(h4.isStandalone);
}
void Ut_PageHandle::testGetStringVariant()
{
    PageHandle h1(PageHandle::MAIN);
    QVERIFY(h1.getStringVariant() == "MAIN:///-1");
    PageHandle h3(PageHandle::APPLET, "datetime", 1);
    QVERIFY(h3.getStringVariant() == "APPLET://datetime/1");
    PageHandle h4(PageHandle::NOPAGE);
    QVERIFY(h4.getStringVariant() == "NOPAGE:///-1");
    PageHandle h13(PageHandle::APPLET);
    QVERIFY(h13.getStringVariant() == "APPLET:///-1");
    PageHandle h15(PageHandle::APPLETCATEGORY, "Connectivity" );
    QCOMPARE(h15.getStringVariant(), QString("APPLETCATEGORY://Connectivity/-1"));
    PageHandle h14(PageHandle::PAGEID_COUNT);
    QVERIFY(h14.getStringVariant() == "PAGEID_COUNT:///-1");
};

void Ut_PageHandle::testEquality()
{
    PageHandle h1(PageHandle::MAIN, "param1", 1);
    PageHandle h2(PageHandle::NOPAGE, "param2", 2);
    QVERIFY(!(h1 == h2));
    h2.id = PageHandle::MAIN;
    h2.param = "param1";
    h2.widgetId = 1;
    QVERIFY(h1 == h2);

};

QTEST_APPLESS_MAIN(Ut_PageHandle)

