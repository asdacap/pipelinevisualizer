PROJECT(DefaultSignalProcessor)
FIND_PACKAGE(QWT5 REQUIRED)
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)
SET(OBJECTS_DIR ../temp/)

SET(DSP_SOURCES
        defaultsignalprocessor.cpp
        doublemultiply.cpp
        variabledoublegeneratorprovider.cpp
        simplelinegraph.cpp
        signalscaler.cpp
        signalexpander.cpp
        signalblockbuilder.cpp
        selectivevaluepipe.cpp
        selectivesignalelimination.cpp
        periodiclistformatter.cpp
        graphabstractionprovider.cpp
        graphabstraction.cpp
        doublegenerator.cpp
        constantdoublegeneratorprovider.cpp
        conditionaloutputsignalpipe.cpp
        conditionalinputsignalpipe.cpp
        booleangeneratorprovider.cpp
        booleangenerator.cpp
        blocknormalizer.cpp
        blocklengthsender.cpp
        blockgenerator.cpp
        signalrepeater.cpp
        plainsignalpipe.cpp
        booleanand.cpp
        booleanor.cpp
        booleanxor.cpp
        booleaninvert.cpp
        doubledivide.cpp
        doubleinverse.cpp
        doubleplus.cpp
        doubleminus.cpp
        integerdivide.cpp
        doubleisgreaterthan.cpp
        doubleislessthan.cpp
        doubleisequal.cpp
        signalmultiply.cpp
        signaldivide.cpp
        signalinverse.cpp
        signalplus.cpp
        signalminus.cpp
        signaldifferentation.cpp
        signalintegration.cpp
        signalsum.cpp
        signaldeviation.cpp
        doublesquareroot.cpp
        signalsquareroot.cpp
        signalmedian.cpp
        signalindex.cpp)

SET(DSP_HEADERS
        booleangenerator.h
        defaultsignalprocessor.h
        doublemultiply.h
        variabledoublegeneratorprovider.h
        simplelinegraph.h
        doublegenerator.h
        signalmedian.h)

QT4_WRAP_CPP(DSP_HEADERS_MOC ${DSP_HEADERS})
ADD_LIBRARY(DefaultSignalProcessor SHARED ${DSP_SOURCES} ${DSP_HEADERS_MOC})

target_link_libraries(DefaultSignalProcessor PVisualizer ${Qwt5_Qt4_LIBRARY})