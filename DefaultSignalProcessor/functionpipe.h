#ifndef FUNCTIONPIPE_H
#define FUNCTIONPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class FunctionPipe: public SignalProcessor
{
public:
    FunctionPipe(double (*funct)(double));
    void feedData(QVector<double> dat, int counter, int channel);
private:
    double (*thefunction)(double);
};

class FunctionPipeProvider:public PipeProcessGraphicsProvider{
public:
    QString name;
    PVisual* PV;
    FunctionPipeProvider(QString thename,double (*funct)(double),PVisual* pv){
        name=thename;
        thefunct=funct;
        PV=pv;
    }

    double (*thefunct)(double);

    QString getName(){
        return name;
    }

    ProcessGraphics* newInstance(QString name){
        FunctionPipe* fp=new FunctionPipe(thefunct);
        return new WidgetedProcessGraphics(fp,name,1,1,0,0,0,0,PV,this);
    }

};

#endif // FUNCTIONPIPE_H
