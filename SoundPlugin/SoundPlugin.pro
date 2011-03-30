
QT       += core
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


win32: LIBS += -L$$PWD/../../portaudio/lib/.libs/ -lportaudio
else:symbian: LIBS += -lportaudiocpp
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lportaudio

win32:INCLUDEPATH += $$PWD/../../portaudio/include
else:unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include
win32:DEPENDPATH += $$PWD/../../portaudio/include
else:unix:DEPENDPATH += $$PWD/../../../../../usr/local/include
