#ifndef PLAINSIGNALPIPE_H
#define PLAINSIGNALPIPE_H
#include "signalprocessor.h"

class PlainSignalPipe:public SignalProcessor
{
public:
    PlainSignalPipe();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // PLAINSIGNALPIPE_H
