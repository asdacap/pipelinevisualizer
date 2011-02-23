#ifndef BLOCKGENERATOR_H
#define BLOCKGENERATOR_H
#include "signalprocessor.h"
#include "doublegenerator.h"
#include "pipeproviderprovider.h"

class BlockGenerator:public SignalProcessor
{
public:
    BlockGenerator(double dat,int length);
    BlockGenerator();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    double getValue(){return val;}
    double getLength(){return leng;}
private:
    bool constantmode;
    double val;
    double leng;
};

class VariableBlockGenerator:public PipeProcessGraphicsProvider{
public:
    VariableBlockGenerator(PVisual* pv);
    PVisual* PV;
    QString getName(){return "VariableBlockGenerator";}
    ProcessGraphics* newInstance(QString name);
};

class ConstantBlockGenerator:public PipeProcessGraphicsProvider{
public:
    ConstantBlockGenerator(PVisual* pv);
    PVisual* PV;
    QString getName(){return "ConstantBlockGenerator";}
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
};

#endif // BLOCKGENERATOR_H
