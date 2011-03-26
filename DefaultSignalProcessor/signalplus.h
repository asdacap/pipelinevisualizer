#ifndef SIGNALPLUS_H
#define SIGNALPLUS_H
#include "signalprocessor.h"

class SignalPlus:public SignalProcessor
{
public:
    SignalPlus();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // SIGNALPLUS_H
