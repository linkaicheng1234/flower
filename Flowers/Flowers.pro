#-------------------------------------------------
#
# Project created by QtCreator 2018-10-20T09:41:39
#
#-------------------------------------------------

QT       += core gui
CONFIG+=qaxcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flowers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cargo.cpp \
    execlist.cpp

HEADERS  += mainwindow.h \
    cargo.h \
    execlist.h

RESOURCES += \
    image.qrc

