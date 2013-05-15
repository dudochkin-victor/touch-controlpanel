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

#ifndef DCPAPPLETMETADATA_P_H
#define DCPAPPLETMETADATA_P_H

#include <QFileInfo>
#include <QDateTime>
#include <MDesktopEntry>
class DcpAppletMetadata;

class DcpAppletMetadataPrivate
{
public:
    DcpAppletMetadataPrivate();
    ~DcpAppletMetadataPrivate();

    bool caWarningIfNotMatch (int key,const QString& expected1,
                              const QString& expected2 = QString());

    // last modification time of the desktop entry:
    QTime m_LastModified;
    MDesktopEntry* m_DesktopEntry;
    QString m_FileName;
    bool m_Disabled;
    int m_Activated;
    static DcpAppletMetadata* sm_LastUsed;
    static QString sm_SOPath;
};

enum  {
    KeyCategory = 0,
    KeyOrder,

    KeyWidgetType,
    KeyAlign,
    KeyToggleIconId,

    KeyText2,
    KeyImage,
    KeyBinary,
    KeyDslFilename,
    KeyApplicationCommand,

    KeyName,
    KeyNameId,
    KeyNameCatalog,

    KeyPart,
    KeyUnique,

    KeyService,
    KeyMethod,
    KeyObjectPath,
    KeyFixedArgs,
    KeyExec,

    KeyHelpId,

    KeyDoNotShowOn,
    KeyOnlyShowOn,

    KeyHasMainView,

    KeySliderLeftImage,
    KeySliderRightImage,

    KeyTextOrientation,
    KeyText2Id,

    KeyCount
};

const QString Keys[KeyCount] = {
    "DCP/Category",
    "DCP/Order",

    "DCP/WidgetType",
    "DCP/Align",
    "DCP/ToggleIconId",

    "DCP/Text2",
    "DCP/Image",
    "DUI/X-DUIApplet-Applet",
    "DUI/X-DUIApplet-Dslfile",
    "DUI/X-DUIApplet-ApplicationCommand",

    "Desktop Entry/Name",
    "Desktop Entry/X-logical-id",
    "Desktop Entry/X-translation-catalog",
    "DCP/Part",

    "DCP/Unique",

    // these have to be filled correctly in order for the .desktop file to be
    // able to function as an action
    "Desktop Entry/X-Maemo-Service",
    "Desktop Entry/X-Maemo-Method",
    "Desktop Entry/X-Maemo-Object-Path",
    "Desktop Entry/X-Maemo-Fixed-Args",
    "Desktop Entry/Exec",

    "DCP/HelpId",
    "DCP/DoNotShowOnProduct",
    "DCP/OnlyShowOnProduct",
    "DCP/HasMainView",
    "DCP/SliderLeftImage",
    "DCP/SliderRightImage",
    "DCP/TextOrientation",
    "DCP/Text2-logical-id"
};

#endif // DCPAPPLETMETADATA_P_H

