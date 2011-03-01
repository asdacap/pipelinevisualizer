#ifndef BLOCKLENGTHSENDER_H
#define BLOCKLENGTHSENDER_H
#include "signalprocessor.h"

class BlockLengthSender:public SignalProcessor
{
public:
    BlockLengthSender();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // BLOCKLENGTHSENDER_H
