#ifndef SIGNALSCALER_H
#define SIGNALSCALER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class SignalScaler:public SignalProcessor
{
public:
    SignalScaler();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat,int counter);
};

class SignalScalerProvider:public PipeProcessGraphicsProvider
{
public:
    SignalScalerProvider(PVisual* pv);
    QString getName();
    ProcessGraphics* newInstance(QString text);
    PVisual* PV;
};

#endif // SIGNALSCALER_H
