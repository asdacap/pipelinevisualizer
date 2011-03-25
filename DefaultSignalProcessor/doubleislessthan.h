#ifndef DOUBLEISLESSTHAN_H
#define DOUBLEISLESSTHAN_H
#include "signalprocessor.h"

class DoubleIsLessThan:public SignalProcessor
{
public:
    DoubleIsLessThan();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // DOUBLEISLESSTHAN_H
