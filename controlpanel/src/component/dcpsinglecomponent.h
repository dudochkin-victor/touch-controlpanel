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

/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */

#ifndef DCPSINGLECOMPONENT_H
#define DCPSINGLECOMPONENT_H

#include <MBasicListItem>
#include "pages.h"
class Category;

class DcpSingleComponent: public MBasicListItem
{
    Q_OBJECT
    Q_PROPERTY (QString mattiID READ mattiID)
    Q_PROPERTY (QString TDriverID READ TDriverID)

public:
    DcpSingleComponent(QGraphicsWidget* parent,
                       const Category* category);
    ~DcpSingleComponent ();

    void setSubPage (const PageHandle &subPage) { m_SubPage = subPage; }
    const PageHandle &subPage() const { return m_SubPage; }

    QString mattiID() const { return m_TDriverID; }
    QString TDriverID() const { return m_TDriverID; }

public slots:
    void activate ();
protected:
    virtual QGraphicsLayout *createLayout();
    virtual void retranslateUi();

private:
    QString m_TDriverID;
    PageHandle m_SubPage;

    const Category* m_Category;

    friend class Ut_DcpSingleComponent;
};

#endif // DCPSINGLECOMPONENT_H

