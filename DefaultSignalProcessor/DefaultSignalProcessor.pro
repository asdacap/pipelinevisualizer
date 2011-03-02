#-------------------------------------------------
#
# Project created by QtCreator 2011-02-25T18:10:46
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = DefaultSignalProcessor
TEMPLATE = lib
CONFIG += plugin
win32:CONFIG(release, debug|release): DESTDIR	+= ../build/release/
else:win32:CONFIG(debug, debug|release): DESTDIR	+= ../build/debug/
else:unix: DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/

SOURCES += \
    defaultsignalprocessor.cpp \
    doublemultiply.cpp \
    pipeproviderprovider.cpp \
    signalprocessor.cpp \
    sppropertydialog.cpp \
    counterkeeper.cpp \
    vectorfunctionpipe.cpp \
    variabledoublegeneratorproviderdialog.cpp \
    variabledoublegeneratorprovider.cpp \
    soundsink.cpp \
    soundfeeder.cpp \
    simplelinegraph.cpp \
    signalscaler.cpp \
    signalexpander.cpp \
    signalblockbuilder.cpp \
    selectivevaluepipe.cpp \
    selectivesignalelimination.cpp \
    pinknoiseremover.cpp \
    periodiclistformatter.cpp \
    inversefftprocessor.cpp \
    harmoniccalculator.cpp \
    hammingwindowmultiplysp.cpp \
    hammingwindowdividesp.cpp \
    graphabstractionprovider.cpp \
    graphabstraction.cpp \
    functionpipe.cpp \
    fftrectangulartopolarconverter.cpp \
    fftprocessor.cpp \
    fftpolartorectangularconverter.cpp \
    doublegenerator.cpp \
    constantdoublegeneratorprovider.cpp \
    conditionaloutputsignalpipe.cpp \
    conditionalinputsignalpipe.cpp \
    booleangeneratorprovider.cpp \
    booleangenerator.cpp \
    blocknormalizer.cpp \
    blocklengthsender.cpp \
    blockgenerator.cpp \
    multivectorfunctionpipe.cpp

HEADERS += \
    defaultsignalprocessor.h \
    doublemultiply.h \
    pipeproviderprovider.h \
    signalprocessor.h \
    providerplugininterface.h \
    sppropertydialog.h \
    counterkeeper.h \
    vectorfunctionpipe.h \
    variabledoublegeneratorproviderdialog.h \
    variabledoublegeneratorprovider.h \
    soundsink.h \
    soundfeeder.h \
    simplelinegraph.h \
    signalscaler.h \
    signalexpander.h \
    signalblockbuilder.h \
    selectivevaluepipe.h \
    selectivesignalelimination.h \
    pinknoiseremover.h \
    periodiclistformatter.h \
    inversefftprocessor.h \
    harmoniccalculator.h \
    hammingwindowmultiplysp.h \
    hammingwindowdividesp.h \
    graphabstractionprovider.h \
    graphabstraction.h \
    functionpipe.h \
    fftrectangulartopolarconverter.h \
    fftprocessor.h \
    fftpolartorectangularconverter.h \
    doublegenerator.h \
    constantdoublegeneratorprovider.h \
    conditionaloutputsignalpipe.h \
    conditionalinputsignalpipe.h \
    booleangeneratorprovider.h \
    booleangenerator.h \
    blocknormalizer.h \
    blocklengthsender.h \
    blockgenerator.h \
    multivectorfunctionpipe.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/local/lib
    }
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/release/ -lPVisualizer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/ -lPVisualizer
else:symbian: LIBS += -lPVisualizer
else:unix: LIBS += -L$$PWD/../build/ -lPVisualizer

INCLUDEPATH += $$PWD/../PipelineVisualizer
DEPENDPATH += $$PWD/../PipelineVisualizer

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:symbian: LIBS += -lqwt
else:unix: LIBS += -L$$PWD/../../../../usr/local/qwt-5.2.1/lib/ -lqwt

win32:INCLUDEPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src
win32:DEPENDPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src
unix:INCLUDEPATH += $$PWD/../../../../usr/local/qwt-5.2.1/include/
unix:DEPENDPATH += $$PWD/../../../../usr/local/qwt-5.2.1/include/


LIBS += -L$$PWD/../../fftw-3.2.2/.libs/ -lfftw3

INCLUDEPATH += $$PWD/../../fftw-3.2.2/api
DEPENDPATH += $$PWD/../../fftw-3.2.2/api

OTHER_FILES +=
