#ifndef CONDITIONALOUTPUTSIGNALPIPE_H
#define CONDITIONALOUTPUTSIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"

class ConditionalOutputSignalPipe:public SignalProcessor
{
public:
    ConditionalOutputSignalPipe();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class ConditionalOutputSignalPipeProvider:public PipeProcessGraphicsProvider{
public:
    ConditionalOutputSignalPipeProvider(PVisual* pv);
    PVisual* PV;
    QString getName();
    ProcessGraphics* newInstance();
};

#endif // CONDITIONALOUTPUTSIGNALPIPE_H
