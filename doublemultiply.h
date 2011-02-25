#ifndef DOUBLEMULTIPLY_H
#define DOUBLEMULTIPLY_H
#include "signalprocessor.h"

class DoubleMultiply:public SignalProcessor
{
public:
    DoubleMultiply();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // DOUBLEMULTIPLY_H
