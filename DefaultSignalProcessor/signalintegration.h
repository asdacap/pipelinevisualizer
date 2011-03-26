#ifndef SIGNALINTEGRATION_H
#define SIGNALINTEGRATION_H
#include "signalprocessor.h"

class SignalIntegration:public SignalProcessor
{
public:
    SignalIntegration();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALINTEGRATION_H
