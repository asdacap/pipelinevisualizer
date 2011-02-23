#ifndef SELECTIVEVALUEPIPE_H
#define SELECTIVEVALUEPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class SelectiveValuePipe:public SignalProcessor
{
public:
    SelectiveValuePipe();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class SelectiveValuePipeProvider:public PipeProcessGraphicsProvider{
public:
    SelectiveValuePipeProvider(PVisual* pv);
    PVisual* PV;
    QString getName(){return "SelectiveValuePipe";}
    ProcessGraphics* newInstance(QString name);
};

#endif // SELECTIVEVALUEPIPE_H
