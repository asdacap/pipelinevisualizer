#ifndef CONDITIONALINPUTSIGNALPIPE_H
#define CONDITIONALINPUTSIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class ConditionalInputSignalPipe:public SignalProcessor
{
public:
    ConditionalInputSignalPipe();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class ConditionalInputSignalPipeProvider:public PipeProcessGraphicsProvider{
public:
    ConditionalInputSignalPipeProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance(QString name);
    QString getName();
};

#endif // CONDITIONALINPUTSIGNALPIPE_H
