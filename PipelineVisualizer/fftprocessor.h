#ifndef FFTPROCESSOR_H
#define FFTPROCESSOR_H
#include "signalprocessor.h"
#include "widgetedprocessgraphics.h"
#include "pipeproviderprovider.h"

class FFTProcessor:public SignalProcessor
{
public:
    FFTProcessor();
    void feedData(QVector<double> dat, int counter, int channel);
};

class FFTProcessorProvider:public PipeProcessGraphicsProvider{
public:
    FFTProcessorProvider(PVisual* pv){PV=pv;}
    PVisual* PV;
    QString getName(){return "FFTProcessor";}
    ProcessGraphics* newInstance(QString text);
};

#endif // FFTPROCESSOR_H
