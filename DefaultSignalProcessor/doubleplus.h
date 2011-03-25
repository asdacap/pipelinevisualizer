#ifndef DOUBLEPLUS_H
#define DOUBLEPLUS_H
#include "signalprocessor.h"

class DoublePlus:public SignalProcessor
{
public:
    DoublePlus();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // DOUBLEPLUS_H
