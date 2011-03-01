#ifndef HAMMINGWINDOWMULTIPLYSP_H
#define HAMMINGWINDOWMULTIPLYSP_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"

class HammingWindowMultiplySP:public SignalProcessor
{
public:
    HammingWindowMultiplySP();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class HammingWindowMultiplySPProvider:public PipeProcessGraphicsProvider{
public:
    HammingWindowMultiplySPProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance(QString name);
    QString getName();
};

#endif // HAMMINGWINDOWMULTIPLYSP_H
