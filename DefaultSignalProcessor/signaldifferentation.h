#ifndef SIGNALDIFFERENTATION_H
#define SIGNALDIFFERENTATION_H
#include "signalprocessor.h"

class SignalDifferentation:public SignalProcessor
{
public:
    SignalDifferentation();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // SIGNALDIFFERENTATION_H
