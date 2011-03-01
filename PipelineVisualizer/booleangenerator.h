#ifndef BOOLEANGENERATOR_H
#define BOOLEANGENERATOR_H
#include "QObject"
#include "signalprocessor.h"

class BooleanGenerator:public QObject,public SignalProcessor
{
    Q_OBJECT
public:
    BooleanGenerator();
    void feedData(QVector<double> dat, int counter, int channel);
    virtual bool getValue();
public slots:
    void setValue(bool val);
private:
    bool cdat;
};

#endif // BOOLEANGENERATOR_H
