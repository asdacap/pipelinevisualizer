#ifndef BOOLEANOR_H
#define BOOLEANOR_H
#include "signalprocessor.h"

class BooleanOr:public SignalProcessor
{
public:
    BooleanOr();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // BOOLEANOR_H
