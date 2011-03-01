#ifndef PERIODICLISTFORMATTER_H
#define PERIODICLISTFORMATTER_H
#include "signalprocessor.h"
#include "pvisual.h"

class PeriodicListFormatter:public SignalProcessor
{
public:
    PeriodicListFormatter(int length);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    void feedBuffer(double dat);
    int getLength(){return curdat.count();}
private:
    int offset;
    QVector<double> curdat;
};

class PeriodicListFormatterProvider: public PipeProcessGraphicsProvider{
public:
    PeriodicListFormatterProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance();
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    QString getName();
};

#endif // PERIODICLISTFORMATTER_H
