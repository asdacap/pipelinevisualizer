#ifndef BOOLEANXOR_H
#define BOOLEANXOR_H
#include "signalprocessor.h"

class BooleanXOr:public SignalProcessor
{
public:
    BooleanXOr();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // BOOLEANXOR_H
