#-------------------------------------------------
#
# Project created by QtCreator 2011-02-25T18:10:46
#
#-------------------------------------------------

QT       += core gui

TARGET = DefaultSignalProcessor
TEMPLATE = lib
CONFIG += plugin
win32:DESTDIR	+= ../win32build/
else:unix:DESTDIR	+= ../unixbuild/
OBJECTS_DIR = ../temp/

SOURCES += \
    defaultsignalprocessor.cpp \
    doublemultiply.cpp \
    variabledoublegeneratorprovider.cpp \
    simplelinegraph.cpp \
    signalscaler.cpp \
    signalexpander.cpp \
    signalblockbuilder.cpp \
    selectivevaluepipe.cpp \
    selectivesignalelimination.cpp \
    periodiclistformatter.cpp \
    graphabstractionprovider.cpp \
    graphabstraction.cpp \
    doublegenerator.cpp \
    constantdoublegeneratorprovider.cpp \
    conditionaloutputsignalpipe.cpp \
    conditionalinputsignalpipe.cpp \
    booleangeneratorprovider.cpp \
    booleangenerator.cpp \
    blocknormalizer.cpp \
    blocklengthsender.cpp \
    blockgenerator.cpp \
    signalrepeater.cpp \
    plainsignalpipe.cpp \
    booleanand.cpp \
    booleanor.cpp \
    booleanxor.cpp \
    booleaninvert.cpp \
    doubledivide.cpp \
    doubleinverse.cpp \
    doubleplus.cpp \
    doubleminus.cpp \
    integerdivide.cpp \
    doubleisgreaterthan.cpp \
    doubleislessthan.cpp \
    doubleisequal.cpp \
    signalmultiply.cpp \
    signaldivide.cpp \
    signalinverse.cpp \
    signalplus.cpp \
    signalminus.cpp \
    signaldifferentation.cpp \
    signalintegration.cpp \
    signalsum.cpp \
    signaldeviation.cpp \
    doublesquareroot.cpp \
    signalsquareroot.cpp \
    signalmedian.cpp \
    signalindex.cpp

HEADERS += \
    defaultsignalprocessor.h \
    doublemultiply.h \
    variabledoublegeneratorprovider.h \
    simplelinegraph.h \
    signalscaler.h \
    signalexpander.h \
    signalblockbuilder.h \
    selectivevaluepipe.h \
    selectivesignalelimination.h \
    periodiclistformatter.h \
    graphabstractionprovider.h \
    graphabstraction.h \
    doublegenerator.h \
    constantdoublegeneratorprovider.h \
    conditionaloutputsignalpipe.h \
    conditionalinputsignalpipe.h \
    booleangeneratorprovider.h \
    booleangenerator.h \
    blocknormalizer.h \
    blocklengthsender.h \
    blockgenerator.h \
    signalrepeater.h \
    plainsignalpipe.h \
    booleanand.h \
    booleanor.h \
    booleanxor.h \
    booleaninvert.h \
    doubledivide.h \
    doubleinverse.h \
    doubleplus.h \
    doubleminus.h \
    integerdivide.h \
    doubleisgreaterthan.h \
    doubleislessthan.h \
    doubleisequal.h \
    signalmultiply.h \
    signaldivide.h \
    signalinverse.h \
    signalplus.h \
    signalminus.h \
    signaldifferentation.h \
    signalintegration.h \
    signalsum.h \
    signaldeviation.h \
    doublesquareroot.h \
    signalsquareroot.h \
    signalmedian.h \
    signalindex.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/local/lib
    }
    INSTALLS += target
}

win32:LIBS += -L$$PWD/../win32build/ -lPVisualizer
else:unix:LIBS += -L$$PWD/../unixbuild/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:symbian: LIBS += -lqwt
else:unix: LIBS += -lqwt

win32:INCLUDEPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src
win32:DEPENDPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src


OTHER_FILES +=
