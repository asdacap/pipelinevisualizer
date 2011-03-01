#ifndef PINKNOISEREMOVER_H
#define PINKNOISEREMOVER_H
#include "signalprocessor.h"
#include "widgetedprocessgraphics.h"
#include "pipeproviderprovider.h"

class PinkNoiseRemover:public SignalProcessor
{
public:
    PinkNoiseRemover();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class PinkNoiseRemoverProvider:public PipeProcessGraphicsProvider{
public:
    PinkNoiseRemoverProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "PinkNoiseRemover";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new PinkNoiseRemover(),name,1,1,1,0,0,0,PV,this);
    }
};

#endif // PINKNOISEREMOVER_H
