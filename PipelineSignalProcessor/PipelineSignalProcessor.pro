#-------------------------------------------------
#
# Project created by QtCreator 2011-02-28T20:42:21
#
#-------------------------------------------------

QT       += core gui
win32:DESTDIR	+= ../win32build/
else:unix:DESTDIR	+= ../unixbuild/
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
    spproviderlistmodel.cpp \
    pipelineprofile.cpp \
    templateprocessor.cpp \
    templateproxy.cpp \
    proccessgraphicspropertymodel.cpp

HEADERS  += \
    tinyxml/tinyxml.h \
    tinyxml/tinystr.h \
    mainprogram.h \
    stringlisteditor.h \
    spproviderlistmodel.h \
    pipelineprofile.h \
    templateprocessor.h \
    templateproxy.h \
    proccessgraphicspropertymodel.h

FORMS    += \
    stringlisteditor.ui

win32:LIBS += -L$$PWD/../win32build/ -lPVisualizer
else:unix:LIBS += -L$$PWD/../unixbuild/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer
