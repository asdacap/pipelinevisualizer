#ifndef SIGNALINVERSE_H
#define SIGNALINVERSE_H
#include "signalprocessor.h"

class SignalInverse:public SignalProcessor
{
public:
    SignalInverse();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALINVERSE_H
