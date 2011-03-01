#-------------------------------------------------
#
# Project created by QtCreator 2011-02-25T18:10:46
#
#-------------------------------------------------

QT       += core gui

TARGET = DefaultSignalProcessor
TEMPLATE = lib
CONFIG += plugin
DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/

SOURCES += \
    defaultsignalprocessor.cpp \
    doublemultiply.cpp \
    pipeproviderprovider.cpp \
    signalprocessor.cpp \
    sppropertydialog.cpp \
    counterkeeper.cpp

HEADERS += \
    defaultsignalprocessor.h \
    doublemultiply.h \
    pipeproviderprovider.h \
    signalprocessor.h \
    providerplugininterface.h \
    sppropertydialog.h \
    counterkeeper.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/local/lib
    }
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/release/ -lPVisualizer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/ -lPVisualizer
else:symbian: LIBS += -lPVisualizer
else:unix: LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
