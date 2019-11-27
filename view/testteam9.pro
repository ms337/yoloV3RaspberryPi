#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T19:10:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = testteam9
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectlist.cpp \
    zonelist.cpp \
    histogram.cpp \
    heatmap.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    objectlist.h \
    ui_mainwindow.h \
    ui_zonelist.h \
    zonelist.h \
    histogram.h \
    heatmap.h \
    qcustomplot.h \
    ui_heatmap.h \
    ui_histogram.h \
    ui_objectlist.h

FORMS    += mainwindow.ui \
    objectlist.ui \
    zonelist.ui \
    histogram.ui \
    heatmap.ui
