#include "conditionalinputsignalpipe.h"
#include "widgetedprocessgraphics.h"

ConditionalInputSignalPipe::ConditionalInputSignalPipe()
{
    setOutputNum(1);
    enableHelper(2,0,1);
}

void ConditionalInputSignalPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat1=dat.at(0);
    QVector<double> dat2=dat.at(1);
    bool condition=booldat.at(0);
    if(condition){
        output_collection.at(0)->feedData(dat1,counter);
    }else{
        output_collection.at(0)->feedData(dat2,counter);
    }
}

QString ConditionalInputSignalPipeProvider::getName(){
    return "ConditionalInputSignalPipe";
}

ConditionalInputSignalPipeProvider::ConditionalInputSignalPipeProvider(PVisual *pv){
    PV=pv;
}

ProcessGraphics* ConditionalInputSignalPipeProvider::newInstance(QString name)
{
    ConditionalInputSignalPipe* sf=new ConditionalInputSignalPipe();
    return new WidgetedProcessGraphics(sf,name,2,1,0,0,1,0,PV,this);
}
