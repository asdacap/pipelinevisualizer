PROJECT(PipelineSignalProcessor)
SET(OBJECTS_DIR ../temp/)

SET(PSP_SOURCES
    tinyxml/tinyxmlparser.cpp 
    tinyxml/tinyxmlerror.cpp 
    tinyxml/tinyxml.cpp 
    tinyxml/tinystr.cpp 
    mainprogram.cpp 
    main.cpp 
    stringlisteditor.cpp 
    spproviderlistmodel.cpp 
    pipelineprofile.cpp 
    templateprocessor.cpp 
    templateproxy.cpp 
    proccessgraphicspropertymodel.cpp )

SET(PSP_HEADERS  
    mainprogram.h 
    stringlisteditor.h 
    spproviderlistmodel.h 
    proccessgraphicspropertymodel.h )

SET(PSP_FORMS   
    stringlisteditor.ui)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_CPP(PSP_HEADERS_MOC ${PSP_HEADERS})
QT4_WRAP_UI(PSP_FORMS_HEADER ${PSP_FORMS})

ADD_EXECUTABLE(PipelineSignalProcessor ${PSP_SOURCES} ${PSP_HEADERS_MOC} ${PSP_FORMS_HEADER}) 

target_link_libraries(PipelineSignalProcessor PVisualizer ${QT_LIBRARIES})