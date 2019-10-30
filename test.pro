#-------------------------------------------------
#
# Project created by QtCreator 2019-10-27T17:42:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectlist.cpp \
    zonelist.cpp \
    Client.cpp \
    Main.cpp

HEADERS  += mainwindow.h \
    objectlist.h \
    zonelist.h

FORMS    += mainwindow.ui \
    objectlist.ui \
    zonelist.ui
