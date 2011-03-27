#ifndef SIGNALSQUAREROOT_H
#define SIGNALSQUAREROOT_H
#include "signalprocessor.h"

class SignalSquareRoot:public SignalProcessor
{
public:
    SignalSquareRoot();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALSQUAREROOT_H
