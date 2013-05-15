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

#include "dcpappletcategorypage.h"
#include "category.h"

DcpAppletCategoryPage::DcpAppletCategoryPage (
        const Category *categoryInfo) :
    m_CategoryInfo (categoryInfo),
    m_Category(0)
{
}

DcpAppletCategoryPage::~DcpAppletCategoryPage ()
{
}


void 
DcpAppletCategoryPage::createContent ()
{
}

const QString 
DcpAppletCategoryPage::appletCategory() const 
{
    return m_CategoryInfo->name();
}

void 
DcpAppletCategoryPage::setCategoryInfo (
        const Category *categoryInfo) 
{
    m_CategoryInfo = categoryInfo;
}


void DcpAppletCategoryPage::back ()
{
}

void
DcpAppletCategoryPage::retranslateUi()
{
}

int
DcpAppletCategoryPage::appletCount()
{
    return 0;
}

DcpAppletMetadata*
DcpAppletCategoryPage::appletMetadata(int)
{
    return 0;
}

void
DcpAppletCategoryPage::onLoadingFinished ()
{
}

void
DcpAppletCategoryPage::mostUsedAppears ()
{
}

