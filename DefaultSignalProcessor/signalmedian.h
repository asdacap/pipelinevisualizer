#ifndef SIGNALMEDIAN_H
#define SIGNALMEDIAN_H
#include "signalprocessor.h"

class SignalMedian:public SignalProcessor
{
public:
    SignalMedian();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALMEDIAN_H
