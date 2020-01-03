PROJECT(FFtPlugin)
FIND_PACKAGE(FFTW REQUIRED)
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)
SET(OBJECTS_DIR ../temp/)

SET(FFT_SOURCES 
    inversefftprocessor.cpp 
    fftrectangulartopolarconverter.cpp 
    fftprocessor.cpp 
    fftpolartorectangularconverter.cpp 
    fftplugin.cpp)

SET(FFT_HEADERS 
    fftplugin.h)

INCLUDE_DIRECTORIES(${FFTW_INCLUDE_DIR})

QT4_WRAP_CPP(FFT_HEADERS_MOC ${FFT_HEADERS})
ADD_LIBRARY(FFtPlugin SHARED ${FFT_SOURCES} ${FFT_HEADERS_MOC})

target_link_libraries(FFtPlugin PVisualizer ${FFTW_LIBRARIES})