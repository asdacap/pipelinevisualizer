#-------------------------------------------------
#
# Project created by QtCreator 2011-01-24T14:47:40
#
#-------------------------------------------------

QT       += core gui multimedia

TARGET = PipelineVisualizer
TEMPLATE = app


SOURCES += main.cpp\
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
    mainwindow.cpp \
    doublegenerator.cpp \
    simplelinegraph.cpp \
    booleangenerator.cpp \
    counterkeeper.cpp \
    graphabstraction.cpp \
    doublelabel.cpp \
    booleanlabel.cpp \
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
    booleangeneratorprovider.cpp

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
    mainwindow.h \
    doublegenerator.h \
    simplelinegraph.h \
    booleangenerator.h \
    counterkeeper.h \
    graphabstraction.h \
    doublelabel.h \
    booleanlabel.h \
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
    booleangeneratorprovider.h

FORMS    += pvisual.ui \
    mainwindow.ui \
    variabledoublegeneratorproviderdialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qwt-5.2.1/qwt-build-desktop/lib/ -lqwt5
else:symbian: LIBS += -lqwt
else:unix: LIBS += -L$$PWD/../qwt-5.2.1/lib/ -lqwt

unix:INCLUDEPATH += $$PWD/../qwt-5.2.1/src
unix:DEPENDPATH += $$PWD/../qwt-5.2.1/src

win32:INCLUDEPATH += $$PWD/../qwt-5.2.1/qwt-5.2.1/src
win32:DEPENDPATH += $$PWD/../qwt-5.2.1/qwt-5.2.1/src

LIBS += -L$$PWD/../fftw-3.2.2/.libs/ -lfftw3

INCLUDEPATH += $$PWD/../fftw-3.2.2/api
DEPENDPATH += $$PWD/../fftw-3.2.2/api
