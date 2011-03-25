#ifndef BOOLEANAND_H
#define BOOLEANAND_H
#include "signalprocessor.h"

class BooleanAnd:public SignalProcessor
{
public:
    BooleanAnd();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // BOOLEANAND_H
