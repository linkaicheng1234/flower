#-------------------------------------------------
#
# Project created by QtCreator 2018-10-20T09:41:39
#
#-------------------------------------------------

QT       += core gui widgets
CONFIG+=qaxcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flowers
TEMPLATE = app

msvc {
    QMAKE_CXXFLAGS -= -WX
}

SOURCES += main.cpp\
        mainwindow.cpp \
    cargo.cpp \
    execlist.cpp \
    widgetitem.cpp \
    widgetitems/menuitem.cpp

INCLUDEPATH += widgetitems/

HEADERS  += mainwindow.h \
    cargo.h \
    execlist.h \
    widgetitem.h \
    widgetitems/menuitem.h

RESOURCES += \
    image.qrc

