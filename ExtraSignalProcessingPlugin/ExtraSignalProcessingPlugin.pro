
QT       += core
TARGET = ExtraSignalProcessingPlugin
TEMPLATE = lib
CONFIG += plugin
DESTDIR	+= ../build/
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

LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
