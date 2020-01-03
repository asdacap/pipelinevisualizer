
PROJECT(SoundPlugin)
FIND_PACKAGE(PORTAUDIO REQUIRED)
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)
SET(OBJECTS_DIR ../temp/)

SET(SP_SOURCES 
    soundsink.cpp 
    soundfeeder.cpp 
    soundplugin.cpp )

SET(SP_HEADERS 
    soundsink.h 
    soundfeeder.h 
    soundplugin.h )

include_directories(${PORTAUDIO_INCLUDE_DIRS})

QT4_WRAP_CPP(SP_HEADERS_MOC ${SP_HEADERS})
ADD_LIBRARY(SoundPlugin SHARED ${SP_SOURCES} ${SP_HEADERS_MOC})

target_link_libraries(SoundPlugin PVisualizer ${PORTAUDIO_LIBRARIES})