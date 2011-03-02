#-------------------------------------------------
#
# Project created by QtCreator 2011-01-24T14:47:40
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = PVisualizer
TEMPLATE = lib
win32:CONFIG(release, debug|release): DESTDIR	+= ../build/release/
else:win32:CONFIG(debug, debug|release): DESTDIR	+= ../build/debug/
else:unix: DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/

SOURCES +=\
        pvisual.cpp \
    pipefeed.cpp \
    pipetarget.cpp \
    processgraphics.cpp \
    targetcollection.cpp \
    pipeprovider.cpp \
    pipeproviderprovider.cpp \
    signalprocessor.cpp \
    constSetting.cpp \
    util.cpp \
    counterkeeper.cpp \
    signalpipefeed.cpp \
    signalpipeprovider.cpp \
    signalpipetarget.cpp \
    doublepipetarget.cpp \
    doublepipeprovider.cpp \
    doublepipefeed.cpp \
    booleanpipetarget.cpp \
    booleanpipeprovider.cpp \
    booleanpipefeed.cpp \
    widgetedprocessgraphics.cpp \
    graphicproxywidgetgraphhack.cpp \
    sppropertydialog.cpp \
    doubleindexvector.cpp \
    linearrow.cpp \
    simpleprocessgraphicsprovidertemplate.cpp \

HEADERS  += pvisual.h \
    pipefeed.h \
    pipetarget.h \
    processgraphics.h \
    targetcollection.h \
    pipeprovider.h \
    pipeproviderprovider.h \
    signalprocessor.h \
    constSetting.h \
    util.h \
    counterkeeper.h \
    signalpipefeed.h \
    signalpipeprovider.h \
    signalpipetarget.h \
    doublepipetarget.h \
    doublepipeprovider.h \
    doublepipefeed.h \
    booleanpipetarget.h \
    booleanpipeprovider.h \
    booleanpipefeed.h \
    widgetedprocessgraphics.h \
    widgetedprocessgraphics.h \
    graphicproxywidgetgraphhack.h \
    sppropertydialog.h \
    providerplugininterface.h \
    blockgenerator.h \
    doubleindexvector.h \
    linearrow.h \
    simpleprocessgraphicsprovidertemplate.h \
    
    




