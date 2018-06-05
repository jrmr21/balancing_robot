QT      += core gui
QT      += network
QT      -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webRobot
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        widget.cpp \
        myudp.cpp

HEADERS += \
        widget.h \
    myudp.h

FORMS += \
        widget.ui

