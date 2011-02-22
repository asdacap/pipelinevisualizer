#ifndef SIGNALBLOCKBUILDER_H
#define SIGNALBLOCKBUILDER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"
#include "widgetedprocessgraphics.h"
#include "QMap"

class SignalBlockBuilderProvider;

class SignalBlockBuilder:public SignalProcessor
{
    friend class SignalBlockBuilderProvider;
public:
    SignalBlockBuilder(int size,int resolution);
    void feedMe(QVector<double>,void* sender=0);
    void feedData(QVector<double> dat, int counter, int channel);
    int* getCounter();
protected:
    int blocksize;
    QVector<double>* inbuffer;
    int buffsize;
    int ct;
    int res;
};

class SignalBlockBuilderProvider:public PipeProcessGraphicsProvider{
public:
    SignalBlockBuilderProvider(PVisual* pv);
    PVisual* PV;
    QString getName();
    ProcessGraphics* newInstance();
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
};

#endif // SIGNALBLOCKBUILDER_H
