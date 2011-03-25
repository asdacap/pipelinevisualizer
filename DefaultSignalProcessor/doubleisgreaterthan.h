#ifndef DOUBLEISGREATERTHAN_H
#define DOUBLEISGREATERTHAN_H
#include "signalprocessor.h"

class DoubleIsGreaterThan:public SignalProcessor
{
public:
    DoubleIsGreaterThan();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // DOUBLEISGREATERTHAN_H
