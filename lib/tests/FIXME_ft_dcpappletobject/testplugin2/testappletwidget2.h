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

#ifndef TESTAPPLETWIDGET2_H__
#define TESTAPPLETWIDGET2_H__

#include <DcpWidget>

class MLayout;
class MLinearLayoutPolicy;
class MLabel; 
class TestAppletWidget2 : public DcpWidget
{
   Q_OBJECT

    public:
       TestAppletWidget2(QGraphicsWidget *parent=0);
       virtual ~TestAppletWidget2();
    private:   
       MLayout *m_Layout; 
       MLinearLayoutPolicy *m_LayoutPolicy;
       MLabel *m_Widget; 
};

#endif
