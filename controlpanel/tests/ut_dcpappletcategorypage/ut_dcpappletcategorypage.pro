include(../common_top.pri)

CONFIG += meegotouch

INCLUDEPATH += $$system(find $$SRCDIR -type d)
INCLUDEPATH += $${LIBDCPINCLUDE}
APPLETDBINCLUDE = $${LIBDCPINCLUDE}/../appletdb
INCLUDEPATH += $${APPLETDBINCLUDE}
INCLUDEPATH += $${STUBSDIR}


TARGET = ut_dcpappletcategorypage

TEST_SOURCES = \
    $$SRCDIR/page/dcpappletcategorypage.cpp \
    $$SRCDIR/page/pages.cpp \
    $$SRCDIR/page/dcppage.cpp \
    $$SRCDIR/categories/category.cpp \
    $$SRCDIR/categories/memorycategory.cpp \

# unit test and unit
SOURCES += \
    ut_dcpappletcategorypage.cpp \
    $$STUBSDIR/mapplication-fake.cpp \
    $$STUBSDIR/mapplicationwindow-fake.cpp \
    $$STUBSDIR/mgridlayoutpolicy-fake.cpp \
    $$STUBSDIR/mabstractlayoutpolicy-fake.cpp \
    $$STUBSDIR/mlayout-fake.cpp \
    $$STUBSDIR/mlinearlayoutpolicy-fake.cpp \
    $$STUBSDIR/mcontainer-fake.cpp \
    $$LIBDCPFAKES/mgconfitem-fake.cpp \
    $$STUBSDIR/dcpappletdb-fake.cpp \
    $$STUBSDIR/dcpappletmetadata-fake.cpp \
    $$STUBSDIR/dcpappletbuttons-fake.cpp \
    $$STUBSDIR/dcpmostused-fake.cpp \
    $$STUBSDIR/dcpappletplugin-fake.cpp \
    $$STUBSDIR/dcpretranslator-fake.cpp \
    $$STUBSDIR/dcpsinglecomponent-fake.cpp \
    $$STUBSDIR/dcpmaincategory-fake.cpp \
    $$STUBSDIR/dcpcategories-fake.cpp \
    $$STUBSDIR/qgraphicsobject-fake.cpp \
    $$TEST_SOURCES \ 

# base classes
SOURCES += \


# unit test and unit
HEADERS += \
    ut_dcpappletcategorypage.h \
    $$STUBSDIR/dcpappletplugin-applet.h \
    $$SRCDIR/component/dcpappletbuttons.h \
    $$SRCDIR/page/dcpappletcategorypage.h \
    $$SRCDIR/page/dcppage.h \
    $$SRCDIR/page/pages.h \
    $$SRCDIR/component/dcpmaincategory.h \
    $$SRCDIR/component/dcpmostused.h \
    $$SRCDIR/component/dcpsinglecomponent.h \

# base classes
HEADERS += \


# service classes
HEADERS += \


