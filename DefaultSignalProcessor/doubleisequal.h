#ifndef DOUBLEISEQUAL_H
#define DOUBLEISEQUAL_H
#include "signalprocessor.h"

class DoubleIsEqual:public SignalProcessor
{
public:
    DoubleIsEqual();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};


#endif // DOUBLEISEQUAL_H
