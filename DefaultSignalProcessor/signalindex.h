#ifndef SIGNALINDEX_H
#define SIGNALINDEX_H
#include "signalprocessor.h"

class SignalIndex:public SignalProcessor
{
public:
    SignalIndex();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALINDEX_H
