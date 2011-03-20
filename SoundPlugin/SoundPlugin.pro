
QT       += core multimedia 
TARGET = SoundPlugin
TEMPLATE = lib
CONFIG += plugin
DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/

SOURCES += \
    soundsink.cpp \
    soundfeeder.cpp \
    soundplugin.cpp \

HEADERS += \
    soundsink.h \
    soundfeeder.h \
    soundplugin.h \

LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
