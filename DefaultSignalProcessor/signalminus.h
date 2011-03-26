#ifndef SIGNALMINUS_H
#define SIGNALMINUS_H
#include "signalprocessor.h"

class SignalMinus:public SignalProcessor
{
public:
    SignalMinus();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};


#endif // SIGNALMINUS_H
