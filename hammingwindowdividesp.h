#ifndef HAMMINGWINDOWDIVIDESP_H
#define HAMMINGWINDOWDIVIDESP_H

#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"

class HammingWindowDivideSP:public SignalProcessor
{
public:
    HammingWindowDivideSP();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class HammingWindowDivideSPProvider:public PipeProcessGraphicsProvider{
public:
    HammingWindowDivideSPProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance(QString name);
    QString getName();
};


#endif // HAMMINGWINDOWDIVIDESP_H
