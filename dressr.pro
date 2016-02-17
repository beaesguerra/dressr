#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T19:48:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dressr
TEMPLATE = app

SOURCES += \
    main.cpp \
    DressrUi.cpp \
    clothingitem.cpp \
    closet.cpp \
    metadatawriter.cpp

HEADERS  += \ 
    DressrUi.h \
    metadatawriter.h \
    clothingitem.h \
    closet.h

FORMS += \
    DressrUi.ui \
    PickUi.ui \
    ClosetUi.ui \
    AddUi.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resources.qrc

