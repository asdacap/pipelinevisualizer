#ifndef DOUBLEDIVIDE_H
#define DOUBLEDIVIDE_H
#include "signalprocessor.h"

class DoubleDivide:public SignalProcessor
{
public:
    DoubleDivide();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // DOUBLEDIVIDE_H
