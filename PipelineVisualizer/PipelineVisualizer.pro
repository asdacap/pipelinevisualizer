#-------------------------------------------------
#
# Project created by QtCreator 2011-01-24T14:47:40
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = PVisualizer
TEMPLATE = lib
DESTDIR	+= ../build/
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
    soundsink.cpp \
    soundfeeder.cpp \
    constSetting.cpp \
    util.cpp \
    doublegenerator.cpp \
    simplelinegraph.cpp \
    booleangenerator.cpp \
    counterkeeper.cpp \
    graphabstraction.cpp \
    signalpipefeed.cpp \
    signalpipeprovider.cpp \
    signalpipetarget.cpp \
    doublepipetarget.cpp \
    doublepipeprovider.cpp \
    doublepipefeed.cpp \
    booleanpipetarget.cpp \
    booleanpipeprovider.cpp \
    booleanpipefeed.cpp \
    variabledoublegeneratorprovider.cpp \
    variabledoublegeneratorproviderdialog.cpp \
    signalscaler.cpp \
    booleangeneratorprovider.cpp \
    conditionaloutputsignalpipe.cpp \
    widgetedprocessgraphics.cpp \
    graphabstractionprovider.cpp \
    graphicproxywidgetgraphhack.cpp \
    conditionalinputsignalpipe.cpp \
    periodiclistformatter.cpp \
    sppropertydialog.cpp \
    hammingwindowmultiplysp.cpp \
    signalblockbuilder.cpp \
    blockgenerator.cpp \
    constantdoublegeneratorprovider.cpp \
    multivectorfunctionpipe.cpp \
    selectivevaluepipe.cpp \
    hammingwindowdividesp.cpp \
    blocknormalizer.cpp \
    fftprocessor.cpp \
    doubleindexvector.cpp \
    signalexpander.cpp \
    fftrectangulartopolarconverter.cpp \
    fftpolartorectangularconverter.cpp \
    inversefftprocessor.cpp \
    selectivesignalelimination.cpp \
    vectorfunctionpipe.cpp \
    pinknoiseremover.cpp \
    functionpipe.cpp \
    signalpipe.cpp \
    linearrow.cpp \
    simpleprocessgraphicsprovidertemplate.cpp \
    blocklengthsender.cpp \
    doublemultiply.cpp \
    harmoniccalculator.cpp

HEADERS  += pvisual.h \
    pipefeed.h \
    pipetarget.h \
    processgraphics.h \
    targetcollection.h \
    pipeprovider.h \
    pipeproviderprovider.h \
    signalprocessor.h \
    soundsink.h \
    soundfeeder.h \
    constSetting.h \
    util.h \
    doublegenerator.h \
    simplelinegraph.h \
    booleangenerator.h \
    counterkeeper.h \
    graphabstraction.h \
    signalpipefeed.h \
    signalpipeprovider.h \
    signalpipetarget.h \
    doublepipetarget.h \
    doublepipeprovider.h \
    doublepipefeed.h \
    booleanpipetarget.h \
    booleanpipeprovider.h \
    booleanpipefeed.h \
    variabledoublegeneratorprovider.h \
    variabledoublegeneratorproviderdialog.h \
    signalscaler.h \
    booleangeneratorprovider.h \
    conditionaloutputsignalpipe.h \
    widgetedprocessgraphics.h \
    widgetedprocessgraphics.h \
    graphabstractionprovider.h \
    graphicproxywidgetgraphhack.h \
    conditionalinputsignalpipe.h \
    periodiclistformatter.h \
    sppropertydialog.h \
    hammingwindowmultiplysp.h \
    signalblockbuilder.h \
    providerplugininterface.h \
    blockgenerator.h \
    constantdoublegeneratorprovider.h \
    multivectorfunctionpipe.h \
    selectivevaluepipe.h \
    hammingwindowdividesp.h \
    blocknormalizer.h \
    fftprocessor.h \
    doubleindexvector.h \
    signalexpander.h \
    fftrectangulartopolarconverter.h \
    fftpolartorectangularconverter.h \
    inversefftprocessor.h \
    selectivesignalelimination.h \
    vectorfunctionpipe.h \
    pinknoiseremover.h \
    functionpipe.h \
    signalpipe.h \
    linearrow.h \
    simpleprocessgraphicsprovidertemplate.h \
    blocklengthsender.h \
    doublemultiply.h \
    harmoniccalculator.h

FORMS    += \
    variabledoublegeneratorproviderdialog.ui
    
    


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/lib/ -lqwt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../qwt-5.2.1/lib/ -lqwt5
else:symbian: LIBS += -lqwt
else:unix: LIBS += -L$$PWD/../../../../usr/local/qwt-5.2.1/lib/ -lqwt

win32:INCLUDEPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src
win32:DEPENDPATH += $$PWD/../../qwt-5.2.1/qwt-5.2.1/src
unix:INCLUDEPATH += $$PWD/../../../../usr/local/qwt-5.2.1/include/
unix:DEPENDPATH += $$PWD/../../../../usr/local/qwt-5.2.1/include/


LIBS += -L$$PWD/../fftw-3.2.2/.libs/ -lfftw3

INCLUDEPATH += $$PWD/../fftw-3.2.2/api
DEPENDPATH += $$PWD/../fftw-3.2.2/api



