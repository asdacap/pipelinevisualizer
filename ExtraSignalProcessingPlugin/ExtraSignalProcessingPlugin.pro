
QT       += core
TARGET = ExtraSignalProcessingPlugin
TEMPLATE = lib
CONFIG += plugin
win32:DESTDIR	+= ../win32build/
else:unix:DESTDIR	+= ../unixbuild/
OBJECTS_DIR = ../temp/

SOURCES += \
    pinknoiseremover.cpp \
    harmoniccalculator.cpp \
    hammingwindowmultiplysp.cpp \
    hammingwindowdividesp.cpp \
    extrasignalprocessor.cpp

HEADERS += \
    harmoniccalculator.h \
    hammingwindowmultiplysp.h \
    hammingwindowdividesp.h \
    pinknoiseremover.h \
    extrasignalprocessor.h

win32:LIBS += -L$$PWD/../win32build/ -lPVisualizer
else:unix:LIBS += -L$$PWD/../unixbuild/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
