#ifndef SIGNALPIPE_H
#define SIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class SignalPipe:public SignalProcessor
{
public:
    SignalPipe();
    void feedData(QVector<double> dat, int counter, int channel);
};

class SignalPipeProcessorProvider:public PipeProcessGraphicsProvider{
public:
    SignalPipeProcessorProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "SignalPipe";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new SignalPipe(),name,2,2,0,0,0,0,PV,this);
    }
};


#endif // SIGNALPIPE_H
