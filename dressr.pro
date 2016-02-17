#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T19:48:37
#
#-------------------------------------------------

TEMPLATE = app
TARGET = dressr

QT       += core gui qml quick multimedia quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += main.cpp\
        DressrUi.cpp \
        clothingitem.cpp \
        closet.cpp \
        metadatawriter.cpp \
    wardrobepicker.cpp \
    outfit.cpp

HEADERS  += \
    DressrUi.h \
    metadatawriter.h \
    clothingitem.h \
    closet.h \
    wardrobepicker.h \
    outfit.h

FORMS += \
    DressrUi.ui \
    PickUi.ui \
    ClosetUi.ui \
    AddUi.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    resources.qrc


# Default rules for deployment.
include(deployment.pri)
