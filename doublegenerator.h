#ifndef DOUBLEGENERATOR_H
#define DOUBLEGENERATOR_H
#include "signalprocessor.h"
#include "QObject"

class DoubleGenerator:public QObject,public SignalProcessor
{
    Q_OBJECT
public:
    DoubleGenerator(double val=0);
    void feedData(QVector<double> dat, int counter, int channel);
    virtual double getValue();
public slots:
    void setValue(double val);
private:
    double cdat;

};

#endif // DOUBLEGENERATOR_H
