#include "multivectorfunctionpipe.h"
#include <iostream>
#include "widgetedprocessgraphics.h"

MultiVectorFunctionPipe::MultiVectorFunctionPipe(int il, int ol, QVector<QVector<double> > (*func)(QVector<QVector<double> >))
{
    thefunc=func;
    setOutputNum(ol);
    enableHelper(il,0,0);
}

void MultiVectorFunctionPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<QVector<double> > result=thefunc(dat);
    int i=0;
    while(i<result.count()){
        output_collection.at(i)->feedData(result.at(i),counter);
        i=i+1;
    }
}

MultiVectorFunctionPipeProvider::MultiVectorFunctionPipeProvider(
    QString name, int in, int on,
    QVector<QVector<double> > (*func)(QVector<QVector<double> >), PVisual *pv){
    thename=name;
    inputNum=in;
    outputNum=on;
    thefunc=func;
    PV=pv;
}

ProcessGraphics* MultiVectorFunctionPipeProvider::newInstance(QString name){
    MultiVectorFunctionPipe* mvfp=new MultiVectorFunctionPipe(inputNum,outputNum,thefunc);
    return new WidgetedProcessGraphics(mvfp,name,inputNum,outputNum,0,0,0,0,PV,this);
}
