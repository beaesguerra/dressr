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
   outfit.cpp \
   PickUi.cpp \
   ClosetUi.cpp \
    addClothesConfirmationUi.cpp \
   ClothesContainer.cpp \
   ClothingThumbnail.cpp \
   AddUi.cpp

HEADERS  += \ 
    DressrUi.h \
    PickUi.h \
    ClosetUi.h \
    ClothesContainer.h \
    ClothingThumbnail.h \
    metadatawriter.h \
    clothingitem.h \
    closet.h \
    wardrobepicker.h \
    outfit.h \
    AddUi.h \
    addClothesConfirmationUi.h

FORMS += \
    DressrUi.ui \
    PickUi.ui \
    ClosetUi.ui \
    AddUi.ui \
    AddClothesConfirmationUi.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    resources.qrc \
    qml.qrc


# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
