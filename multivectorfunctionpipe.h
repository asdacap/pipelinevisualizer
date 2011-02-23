#ifndef MULTIVECTORFUNCTIONPIPE_H
#define MULTIVECTORFUNCTIONPIPE_H
#include <QVector>
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class MultiVectorFunctionPipe: public SignalProcessor
{
public:
    MultiVectorFunctionPipe(int il,int ol,QVector<QVector<double> > (*func)(QVector<QVector<double> > dat));
    void feedMe(QVector<double>, void *sender);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);

private:
    QVector<QVector<double> > (*thefunc)(QVector<QVector<double> > dat);
};

class MultiVectorFunctionPipeProvider:public PipeProcessGraphicsProvider{
public:
    MultiVectorFunctionPipeProvider(QString name,int in,int on,QVector<QVector<double> > (*func)(QVector<QVector<double> > dat),PVisual* pv);
    PVisual* PV;
    QString thename;
    int inputNum;
    int outputNum;
    QVector<QVector<double> > (*thefunc)(QVector<QVector<double> > dat);
    QString getName(){return thename;}
    ProcessGraphics* newInstance(QString name);
};

#endif // MULTIVECTORFUNCTIONPIPE_H
