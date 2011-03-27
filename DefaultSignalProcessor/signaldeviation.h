#ifndef SIGNALDEVIATION_H
#define SIGNALDEVIATION_H
#include "signalprocessor.h"

class SignalDeviation:public SignalProcessor
{
public:
    SignalDeviation();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALDEVIATION_H
