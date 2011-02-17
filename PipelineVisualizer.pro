#-------------------------------------------------
#
# Project created by QtCreator 2011-01-24T14:47:40
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = PipelineVisualizer
TEMPLATE = app


SOURCES += main.cpp\
        pvisual.cpp \
    pipefeed.cpp \
    pipetarget.cpp \
    processgraphics.cpp \
    targetcollection.cpp \
    pipeprovider.cpp \
    StaticData.cpp \
    pipeproviderprovider.cpp \
    signalprocessor.cpp \
    soundsink.cpp \
    soundfeeder.cpp \
    constSetting.cpp \
    util.cpp

HEADERS  += pvisual.h \
    pipefeed.h \
    pipetarget.h \
    processgraphics.h \
    targetcollection.h \
    pipeprovider.h \
    StaticData.h \
    pipeproviderprovider.h \
    signalprocessor.h \
    soundsink.h \
    soundfeeder.h \
    constSetting.h \
    util.h

FORMS    += pvisual.ui
