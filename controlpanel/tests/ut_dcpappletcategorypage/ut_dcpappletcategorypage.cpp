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

#include <dcpappletcategorypage.h>
#include <dcpmaincategory.h>
#include <category.h>
#include <dcpcategories.h>

#define CATEGORY DcpCategories::instance()->categoryById("fake-category")
#define CATEGORY2 DcpCategories::instance()->categoryById("ZERO")

#include "ut_dcpappletcategorypage.h"

void Ut_DcpAppletCategoryPage::init()
{
    m_subject = new DcpAppletCategoryPage(CATEGORY);

}

void Ut_DcpAppletCategoryPage::cleanup()
{
    delete m_subject;
    m_subject = 0;
}

void Ut_DcpAppletCategoryPage::initTestCase()
{
    QSKIP("incomplete", SkipSingle);   // remove this when you've finished
}

void Ut_DcpAppletCategoryPage::cleanupTestCase()
{
}

void Ut_DcpAppletCategoryPage::testCreation()
{
    QVERIFY(m_subject);
    QCOMPARE((void*)m_subject->m_CategoryInfo, (void*)(CATEGORY));
//    QCOMPARE(m_subject->m_Category->maxColumns(), 2);
}

void Ut_DcpAppletCategoryPage::testCreateContent()
{
    m_subject->createContent();
}

void Ut_DcpAppletCategoryPage::testAppletCategory()
{
    QCOMPARE(m_subject->appletCategory(), QString("FAKE-CATEGORY"));
    m_subject->setCategoryInfo(CATEGORY2);
    QCOMPARE(m_subject->appletCategory(), QString("ZERO"));
}

void Ut_DcpAppletCategoryPage::testCategoryInfo()
{
    m_subject->setCategoryInfo(CATEGORY2);
    QCOMPARE((void*)m_subject->m_CategoryInfo, (void*)(CATEGORY2));
  
}

void Ut_DcpAppletCategoryPage::testReload()
{
    m_subject->createContent();
    m_subject->reload();
}

void Ut_DcpAppletCategoryPage::testCleanup()
{
    QSKIP("incomplete", SkipSingle);   // remove this when you've finished
}

void Ut_DcpAppletCategoryPage::testBack()
{
    m_subject->back();
}

void Ut_DcpAppletCategoryPage::testRetranslateUi()
{
    m_subject->m_CategoryInfo = CATEGORY2;
    m_subject->retranslateUi();
    QCOMPARE(m_subject->title(), QString("!! ZERO"));
}

void Ut_DcpAppletCategoryPage::testAddComponent()
{
    QSKIP("incomplete", SkipSingle);   // remove this when you've finished
}

QTEST_APPLESS_MAIN(Ut_DcpAppletCategoryPage)

