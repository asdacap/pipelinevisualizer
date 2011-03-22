#-------------------------------------------------
#
# Project created by QtCreator 2011-02-28T20:42:21
#
#-------------------------------------------------

QT       += core gui multimedia
DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/
TARGET = PipelineSignalProcessor
TEMPLATE = app


SOURCES += \
    tinyxml/tinyxmlparser.cpp \
    tinyxml/tinyxmlerror.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinystr.cpp \
    mainprogram.cpp \
    main.cpp \
    stringlisteditor.cpp \
    spproviderlistmodel.cpp

HEADERS  += \
    tinyxml/tinyxml.h \
    tinyxml/tinystr.h \
    mainprogram.h \
    stringlisteditor.h \
    spproviderlistmodel.h

FORMS    += \
    pluginlisteditor.ui \
    stringlisteditor.ui

LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
