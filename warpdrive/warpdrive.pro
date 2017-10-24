#-------------------------------------------------
#
# Project created by QtCreator 2017-10-23T11:59:05
#
#-------------------------------------------------
QT += websockets qml
QT       -= gui

TEMPLATE = lib

DEFINES += WARPDRIVE_LIBRARY

CONFIG += c++11
DESTDIR = $$PWD/../out

CONFIG(release, debug|release):TARGET = warpdrive
CONFIG(debug, debug|release):TARGET = warpdrived

#INCLUDEPATH += \

include(../3rdparty/simplerpc/simplerpc.pri)

SOURCES += \
        warpdrive.cpp

HEADERS += \
        warpdrive.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
