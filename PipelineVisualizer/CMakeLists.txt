
PROJECT(PVisualizer)
set(PV_SOURCES
pvisual.cpp 
    pipefeed.cpp 
    pipetarget.cpp 
    processgraphics.cpp 
    targetcollection.cpp 
    pipeprovider.cpp 
    pipeproviderprovider.cpp 
    signalprocessor.cpp 
    constSetting.cpp 
    util.cpp 
    counterkeeper.cpp 
    signalpipefeed.cpp 
    signalpipeprovider.cpp 
    signalpipetarget.cpp 
    doublepipetarget.cpp 
    doublepipeprovider.cpp 
    doublepipefeed.cpp 
    booleanpipetarget.cpp 
    booleanpipeprovider.cpp 
    booleanpipefeed.cpp 
    widgetedprocessgraphics.cpp 
    graphicproxywidgetgraphhack.cpp 
    sppropertydialog.cpp 
    doubleindexvector.cpp 
    linearrow.cpp 
    simpleprocessgraphicsprovidertemplate.cpp 
    functionpipe.cpp 
    multivectorfunctionpipe.cpp 
    vectorfunctionpipe.cpp
)

set(PV_HEADERS
    pvisual.h 
    processgraphics.h 
    widgetedprocessgraphics.h 
    widgetedprocessgraphics.h 
    sppropertydialog.h)

set(PV_FORMS
variabledoublegeneratorproviderdialog.ui
)

QT4_WRAP_CPP(PV_HEADERS_MOC ${PV_HEADERS})
QT4_WRAP_UI(PV_FORMS_HEADER ${PV_FORMS})

SET(OBJECTS_DIR ../temp/)
    
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_library(PVisualizer SHARED ${PV_SOURCES} ${PV_HEADERS_MOC} ${PV_FORMS_HEADER})
TARGET_LINK_LIBRARIES(PVisualizer ${QT_LIBRARIES})