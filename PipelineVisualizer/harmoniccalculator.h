#ifndef HARMONICCALCULATOR_H
#define HARMONICCALCULATOR_H
#include "signalpipe.h"
#include "doubleindexvector.h"
#include "constSetting.h"
#include "signalprocessor.h"

class HarmonicCalculator:public SignalProcessor
{
public:
    HarmonicCalculator();
    virtual double sumIt(DoubleIndexVector* ind,double index);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    double interval;
};

#endif // HARMONICCALCULATOR_H
