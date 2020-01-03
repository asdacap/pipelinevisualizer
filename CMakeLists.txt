PROJECT(PipelineVisualizer)
FIND_PACKAGE(Qt4 REQUIRED)
cmake_minimum_required(VERSION 2.8)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmakeModules/")

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

include_directories("${PROJECT_SOURCE_DIR}/PipelineVisualizer")
add_subdirectory(PipelineVisualizer )
add_subdirectory(PipelineSignalProcessor )
add_subdirectory(DefaultSignalProcessor )
add_subdirectory(SoundPlugin )
add_subdirectory(ExtraSignalProcessingPlugin )
add_subdirectory(FFtPlugin) 
