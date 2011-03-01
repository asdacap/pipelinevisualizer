#ifndef SIGNALEXPANDER_H
#define SIGNALEXPANDER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class SignalExpander:public SignalProcessor
{
public:
    SignalExpander();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class SignalExpanderProvider:public PipeProcessGraphicsProvider{
public:
    SignalExpanderProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "SignalExpander";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new SignalExpander(),name,1,1,2,0,1,0,PV,this);
    }
};

#endif // SIGNALEXPANDER_H
