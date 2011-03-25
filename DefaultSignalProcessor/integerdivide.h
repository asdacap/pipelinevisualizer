#ifndef INTEGERDIVIDE_H
#define INTEGERDIVIDE_H
#include "signalprocessor.h"

class IntegerDivide:public SignalProcessor
{
public:
    IntegerDivide();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // INTEGERDIVIDE_H
