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

/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */
#include "dcpstylablewidget.h"
#include "dcpstylablewidget_p.h"

#include "dcpdebug.h"


DcpStylableWidgetPrivate::DcpStylableWidgetPrivate ():
    m_WidgetId (-1),
    isProgressIndicatorVisible (false)
{
}


/*!
 * \brief The constructor. No referer for default
 */
DcpStylableWidget::DcpStylableWidget (QGraphicsWidget *parent) 
    : MStylableWidget (parent), 
      d_ptr (new DcpStylableWidgetPrivate)
{
    DCP_DEBUG ("*** this = %p", this);
}

DcpStylableWidget::~DcpStylableWidget ()
{
    DCP_DEBUG ("*** this = %p", this);
    delete d_ptr;
}


/*!
 *
 * Returns the widgetId for the DcpStylableWidget object.
 */
int 
DcpStylableWidget::getWidgetId ()
{
    return d_ptr->m_WidgetId;
}

/*!
 * \brief Sets the widgetId and returns true if the ID could be set.
 *
 * Sets the widgetId for the DcpStylableWidget class widget. The WidgetId is set by the
 * controlpanel, and should not changed by the cp applet. Once the widgetId is
 * set it can not be changed.
 */
bool 
DcpStylableWidget::setWidgetId (
        int widgetId)
{
    DCP_DEBUG ("*** this       = %p", this);
    DCP_DEBUG ("*** widgetId   = %d", widgetId);
    DCP_DEBUG ("*** m_WidgetId = %d", d_ptr->m_WidgetId);

    if (d_ptr->m_WidgetId != -1) {
        DCP_WARNING ("The widgetId already set.");
        return false;
    }

    if (widgetId < 0) {
        DCP_CRITICAL ("The widgetId should be >= 0.");
    }

    d_ptr->m_WidgetId = widgetId;
    return true;
}

/*! 
 * \brief deprecated function
 * \param widgetId
 * This function is no longer in use, kept only for
 * preserving binary compatibility.
 */
void
DcpStylableWidget::setReferer (int widgetId)
{
    Q_UNUSED (widgetId);
    // FIXME: remove this function
}

/*!
 * \brief This method gets called when user presses 'Back' on the applet page
 * \return true if back should close the page and false if not
 */
bool 
DcpStylableWidget::back ()
{
    // back closes the page by default
    return true;
}

/*!
 * The pannable area for the entire view (page) will be enabled if this function
 * returns true. The default implementation of the function returns true, so the
 * pannable area will be enabled.
 */
bool 
DcpStylableWidget::pagePans () const 
{
    return true; 
}

QString
DcpStylableWidget::title() const
{
    return QString();
}

void DcpStylableWidget::setProgressIndicatorVisible(bool visible)
{
    d_ptr->isProgressIndicatorVisible = visible;
    emit inProgress (visible);
}

bool DcpStylableWidget::isProgressIndicatorVisible() const
{
    return d_ptr->isProgressIndicatorVisible;
}


