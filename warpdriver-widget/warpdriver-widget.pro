#-------------------------------------------------
#
# Project created by QtCreator 2017-10-23T13:47:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warpdriver-widget
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/../out

CONFIG(release, debug|release):TARGET = warpdriver-widget
CONFIG(debug, debug|release):TARGET = warpdriver-widgetd


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/ -lwarpdrive
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/ -lwarpdrived
else:unix: LIBS += -L$$DESTDIR/ -lwarpdrive

INCLUDEPATH += $$PWD/../warpdrive
DEPENDPATH += $$PWD/../warpdrive
