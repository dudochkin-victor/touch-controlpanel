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

#include <QString>

#include <dcpmostusedcounter.h>
#include "mgconfitem-fake.h"


#include "ut_dcpmostusedcounter.h"


void Ut_DcpMostUsedCounter::init()
{
    m_subject = MostUsedCounter::instance();
}

void Ut_DcpMostUsedCounter::cleanup()
{
    MostUsedCounter::destroy();
    emptyFakeGConf();
    m_subject = 0;
}

void Ut_DcpMostUsedCounter::initTestCase()
{
}

void Ut_DcpMostUsedCounter::cleanupTestCase()
{
}

void Ut_DcpMostUsedCounter::testAddToEmpty()
{
    const QString key("foo");
    QCOMPARE(m_subject->getUsageCount(key), 0);
    m_subject->incrementUsageCount(key);
    QCOMPARE(m_subject->getUsageCount(key), 1);
}

void Ut_DcpMostUsedCounter::testAddMultipleTimes()
{
    const QString key("foo");
    QCOMPARE(m_subject->getUsageCount(key), 0);
    const int n = 100;
    for (int i = 1; i < n; ++i) {
        m_subject->incrementUsageCount(key);
        QCOMPARE(m_subject->getUsageCount(key), i);
    }
}

void Ut_DcpMostUsedCounter::testClearNonAdded()
{
    const QString key1("foo");
    const QString key2("bar");

    m_subject->dropKey (key1);
    QCOMPARE(m_subject->getUsageCount(key1), 0);

    m_subject->incrementUsageCount(key2);
    m_subject->dropKey (key1);
    QCOMPARE(m_subject->getUsageCount(key1), 0);
    QCOMPARE(m_subject->getUsageCount(key2), 1);
}

void Ut_DcpMostUsedCounter::testClearAdded()
{
    const QString key1("foo");
    const QString key2("bar");

    QCOMPARE(m_subject->getUsageCount(key2), 0);
    m_subject->incrementUsageCount(key1);
    m_subject->dropKey (key1);
    QCOMPARE(m_subject->getUsageCount(key1), 0);

    m_subject->incrementUsageCount(key1);
    m_subject->incrementUsageCount(key2);
    m_subject->dropKey (key1);
    QCOMPARE(m_subject->getUsageCount(key1), 0);
    QCOMPARE(m_subject->getUsageCount(key2), 1);
}

QTEST_APPLESS_MAIN(Ut_DcpMostUsedCounter)
