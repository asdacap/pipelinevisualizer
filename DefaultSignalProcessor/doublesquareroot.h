#ifndef DOUBLESQUAREROOT_H
#define DOUBLESQUAREROOT_H
#include "signalprocessor.h"

class DoubleSquareRoot:public SignalProcessor
{
public:
    DoubleSquareRoot();
    void feedDoubleData(double dat, int counter, int channel);
};

#endif // DOUBLESQUAREROOT_H
