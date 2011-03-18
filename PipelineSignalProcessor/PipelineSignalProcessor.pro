#-------------------------------------------------
#
# Project created by QtCreator 2011-02-28T20:42:21
#
#-------------------------------------------------

QT       += core gui multimedia
DESTDIR	+= ../build/
OBJECTS_DIR = ../temp/
TARGET = PipelineSignalProcessor
TEMPLATE = app


SOURCES += \
    tinyxml/tinyxmlparser.cpp \
    tinyxml/tinyxmlerror.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinystr.cpp \
    mainprogram.cpp \
    main.cpp \
    stringlisteditor.cpp

HEADERS  += \
    tinyxml/tinyxml.h \
    tinyxml/tinystr.h \
    mainprogram.h \
    stringlisteditor.h

FORMS    += \
    pluginlisteditor.ui \
    stringlisteditor.ui

LIBS += -L$$PWD/../build/ -lPVisualizer

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
