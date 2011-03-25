#ifndef DOUBLEMINUS_H
#define DOUBLEMINUS_H
#include "signalprocessor.h"

class DoubleMinus:public SignalProcessor
{
public:
    DoubleMinus();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};


#endif // DOUBLEMINUS_H
