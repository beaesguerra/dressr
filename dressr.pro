#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T19:48:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dressr
TEMPLATE = app


SOURCES += main.cpp\
        dressr.cpp

HEADERS  += dressr.h

FORMS    += dressr.ui \
    pick.ui \
    browse.ui \
    new.ui

CONFIG += mobility
MOBILITY = 

