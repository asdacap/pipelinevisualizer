
QT       += core
TARGET = FFtPlugin
TEMPLATE = lib
CONFIG += plugin
win32:DESTDIR	+= ../win32build/
else:unix:DESTDIR	+= ../unixbuild/
OBJECTS_DIR = ../temp/

SOURCES += \
    inversefftprocessor.cpp \
    fftrectangulartopolarconverter.cpp \
    fftprocessor.cpp \
    fftpolartorectangularconverter.cpp \
    fftplugin.cpp

HEADERS += \
    fftrectangulartopolarconverter.h \
    fftprocessor.h \
    fftpolartorectangularconverter.h \
    inversefftprocessor.h \
    fftplugin.h

win32:LIBS += -L$$PWD/../win32build/ -lPVisualizer
else:unix:LIBS += -L$$PWD/../unixbuild/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer

LIBS += -L$$PWD/../../fftw-3.2.2/.libs/ -lfftw3

INCLUDEPATH += $$PWD/../../fftw-3.2.2/api
DEPENDPATH += $$PWD/../../fftw-3.2.2/api
