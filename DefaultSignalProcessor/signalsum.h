#ifndef SIGNALSUM_H
#define SIGNALSUM_H
#include "signalprocessor.h"

class SignalSum:public SignalProcessor
{
public:
    SignalSum();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALSUM_H
