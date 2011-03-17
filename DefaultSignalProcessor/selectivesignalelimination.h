#ifndef SELECTIVESIGNALELIMINATION_H
#define SELECTIVESIGNALELIMINATION_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class SelectiveSignalElimination:public SignalProcessor
{
public:
    SelectiveSignalElimination();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class SelectiveSignalEliminationProvider:public PipeProcessGraphicsProvider{
public:
    SelectiveSignalEliminationProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "SelectiveSignalElimination";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new SelectiveSignalElimination(),name,2,2,0,0,0,0,PV,this);
    }
};


#endif // SELECTIVESIGNALELIMINATION_H
