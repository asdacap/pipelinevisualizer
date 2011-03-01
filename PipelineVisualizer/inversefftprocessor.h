#ifndef INVERSEFFTPROCESSOR_H
#define INVERSEFFTPROCESSOR_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class InverseFFtProcessor:public SignalProcessor
{
public:
    InverseFFtProcessor();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class InverseFFtProcessorProvider:public PipeProcessGraphicsProvider{
public:
    InverseFFtProcessorProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "InverseFFtProcessor";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new InverseFFtProcessor(),name,2,1,0,0,0,0,PV,this);
    }
};


#endif // INVERSEFFTPROCESSOR_H
