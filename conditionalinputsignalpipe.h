#ifndef CONDITIONALINPUTSIGNALPIPE_H
#define CONDITIONALINPUTSIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class ConditionalInputSignalPipe:public SignalProcessor
{
public:
    ConditionalInputSignalPipe();
    void feedData(QVector<double> dat, int counter, int channel);
    void feedBoolData(bool dat, int counter, int channel);
    int currentCounter;
    QVector<double> datchan1;
    QVector<double> datchan2;
    bool tempbol;
    bool dat1set;
    bool dat2set;
    bool bolset;
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
