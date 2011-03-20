
QT       += core
TARGET = FFtPlugin
TEMPLATE = lib
CONFIG += plugin
DESTDIR	+= ../build/
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

LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer

LIBS += -L$$PWD/../../fftw-3.2.2/.libs/ -lfftw3

INCLUDEPATH += $$PWD/../../fftw-3.2.2/api
DEPENDPATH += $$PWD/../../fftw-3.2.2/api
