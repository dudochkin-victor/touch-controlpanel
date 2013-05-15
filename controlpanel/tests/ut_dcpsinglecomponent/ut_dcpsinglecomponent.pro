include(../common_top.pri)
CONFIG += meegotouch
INCLUDEPATH += $$system(find $$SRCDIR -type d)
INCLUDEPATH += ../doubles 
INCLUDEPATH += $$LIBDCPSRC
INCLUDEPATH += $$LIBDCPSRC/appletdb 

TARGET = ut_dcpsinglecomponent

TEST_SOURCES = \
    $$SRCDIR/component/dcpsinglecomponent.cpp \
    $$SRCDIR/page/pages.cpp \
    $$SRCDIR/categories/category.cpp \
    $$SRCDIR/categories/memorycategory.cpp \
    ../doubles/pagefactory-fake.cpp \
    ../doubles/dcppage-fake.cpp \
    ../doubles/dcpappletplugin-fake.cpp \
    ../doubles/mdesktopentry-fake.cpp \
    ../doubles/mbasiclistitem-fake.cpp \
    $$LIBDCPFAKES/mgconfitem-fake.cpp \
    $$LIBDCPFAKES/mimagewidget-fake.cpp \
    ../doubles/mapplication-fake.cpp \
    ../doubles/mapplicationpage-fake.cpp \
    ../doubles/mapplicationwindow-fake.cpp \

# unit test and unit
SOURCES += \
    ut_dcpsinglecomponent.cpp \
    $$TEST_SOURCES \ 

# base classes
SOURCES += \


# unit test and unit
HEADERS += \
    ut_dcpsinglecomponent.h \
    $$SRCDIR/component/dcpsinglecomponent.h \
    $$SRCDIR/page/pages.h \
    $$SRCDIR/page/dcppage.h \
    $$SRCDIR/page/pagefactory.h \
    $$SRCDIR/categories/category.h \
    $$SRCDIR/categories/memorycategory.h \
    $$STUBSDIR/dcpappletplugin-applet.h \

# base classes
HEADERS += \


# service classes
HEADERS += \


