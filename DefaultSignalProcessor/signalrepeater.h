#ifndef SIGNALREPEATER_H
#define SIGNALREPEATER_H
#include "signalprocessor.h"

class SignalRepeater:public SignalProcessor
{
public:
    SignalRepeater();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

#endif // SIGNALREPEATER_H
