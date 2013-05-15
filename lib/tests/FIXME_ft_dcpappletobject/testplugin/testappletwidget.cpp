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

#include <MLabel>
#include <MContainer>
#include <MLayout>
#include <MLinearLayoutPolicy>
#include <MButton>
#include <MButtonGroup>
#include "testappletwidget.h"

TestAppletWidget::TestAppletWidget(QGraphicsWidget *parent)
    : DcpWidget(parent)
{
    MLayout *layout = new MLayout(this);
    m_layoutPolicy = 
        new MLinearLayoutPolicy(layout, Qt::Vertical);
    layout->setPolicy(m_layoutPolicy);

    MLabel *widget = new MLabel("Test applet1", this);
    m_layoutPolicy->addItem(widget, Qt::AlignLeft);

    setLayout(layout);

}

TestAppletWidget::~TestAppletWidget()
{
}

