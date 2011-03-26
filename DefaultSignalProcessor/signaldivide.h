#ifndef SIGNALDIVIDE_H
#define SIGNALDIVIDE_H
#include "signalprocessor.h"

class SignalDivide:public SignalProcessor
{
public:
    SignalDivide();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};


#endif // SIGNALDIVIDE_H
