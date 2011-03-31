
QT       += core
TARGET = SoundPlugin
TEMPLATE = lib
CONFIG += plugin
win32:DESTDIR	+= ../win32build/
else:unix:DESTDIR	+= ../unixbuild/
OBJECTS_DIR = ../temp/

SOURCES += \
    soundsink.cpp \
    soundfeeder.cpp \
    soundplugin.cpp \

HEADERS += \
    soundsink.h \
    soundfeeder.h \
    soundplugin.h \

win32:LIBS += -L$$PWD/../win32build/ -lPVisualizer
else:unix:LIBS += -L$$PWD/../unixbuild/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer


win32: LIBS += -L$$PWD/../../portaudio/lib/.libs/ -lportaudio
else:symbian: LIBS += -lportaudiocpp
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lportaudio

win32:INCLUDEPATH += $$PWD/../../portaudio/include
else:unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include
win32:DEPENDPATH += $$PWD/../../portaudio/include
else:unix:DEPENDPATH += $$PWD/../../../../../usr/local/include
