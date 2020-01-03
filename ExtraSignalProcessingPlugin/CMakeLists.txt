PROJECT(ExtraSignalProcessing)
FIND_PACKAGE(QWT5 REQUIRED)
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)
SET(OBJECTS_DIR ../temp/)

SET(ESP_SOURCES
        pinknoiseremover.cpp
        harmoniccalculator.cpp
        hammingwindowmultiplysp.cpp
        hammingwindowdividesp.cpp
        extrasignalprocessor.cpp)

SET(ESP_HEADERS
        harmoniccalculator.h
        hammingwindowmultiplysp.h
        hammingwindowdividesp.h
        pinknoiseremover.h
        extrasignalprocessor.h)

QT4_WRAP_CPP(ESP_HEADERS_MOC ${ESP_HEADERS})
ADD_LIBRARY(ExtraSignalProcessing SHARED ${ESP_SOURCES} ${ESP_HEADERS_MOC})

target_link_libraries(ExtraSignalProcessing PVisualizer ${Qwt5_Qt4_LIBRARY})
