QT += quick

CONFIG += c++11
DESTDIR = $$PWD/../out

CONFIG(release, debug|release):TARGET = warpdriver
CONFIG(debug, debug|release):TARGET = warpdriverd

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/ -lwarpdrive
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/ -lwarpdrived
else:unix: LIBS += -L$$DESTDIR/ -lwarpdrive

INCLUDEPATH += $$PWD/../warpdrive
DEPENDPATH += $$PWD/../warpdrive
