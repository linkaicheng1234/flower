#-------------------------------------------------
#
# Project created by QtCreator 2018-10-20T09:41:39
#
#-------------------------------------------------


#CONFIG+=qaxcontainer
QT       +=  core gui sql widgets axcontainer

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
    widgetitems/menuitem.cpp \
    widgetitems/ordermanage.cpp
    clientmes.cpp

INCLUDEPATH += widgetitems/

HEADERS  += mainwindow.h \
    cargo.h \
    execlist.h \
    widgetitem.h \
    widgetitems/menuitem.h \
    widgetitems/ordermanage.h
    clientmes.h

RESOURCES += \
    image.qrc


