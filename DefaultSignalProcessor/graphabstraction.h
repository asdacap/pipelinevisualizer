#ifndef GRAPHABSTRACTION_H
#define GRAPHABSTRACTION_H
#include "signalprocessor.h"
#include "counterkeeper.h"
#include <QString>

class GraphAbstraction:public SignalProcessor
{
public:
    GraphAbstraction(QString name);
    void feedData(QVector<double> dat, int counter, int channel);
    void lock();
    void unlock();
    QString getName();
    QString name;
    bool locked;
    QVector<double> xdata;
    QVector<double> ydata;
    CounterKeeper* thekeeper;
};

#endif // GRAPHABSTRACTION_H
