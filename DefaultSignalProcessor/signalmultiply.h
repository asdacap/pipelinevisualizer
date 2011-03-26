#ifndef SIGNALMULTIPLY_H
#define SIGNALMULTIPLY_H
#include "signalprocessor.h"

class SignalMultiply:public SignalProcessor
{
public:
    SignalMultiply();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // SIGNALMULTIPLY_H
