#ifndef BOOLEANINVERT_H
#define BOOLEANINVERT_H
#include "signalprocessor.h"

class BooleanInvert:public SignalProcessor
{
public:
    BooleanInvert();
    void feedBoolData(bool dat, int counter, int channel);
};

#endif // BOOLEANINVERT_H
