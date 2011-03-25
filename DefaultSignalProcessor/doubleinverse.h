#ifndef DOUBLEINVERSE_H
#define DOUBLEINVERSE_H
#include "signalprocessor.h"

class DoubleInverse:public SignalProcessor
{
public:
    DoubleInverse();
    void feedDoubleData(double dat, int counter, int channel);
};

#endif // DOUBLEINVERSE_H
