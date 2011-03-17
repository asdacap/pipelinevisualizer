#include "signalscaler.h"
#include "QInputDialog"
#include <iostream>
#include "widgetedprocessgraphics.h"

SignalScaler::SignalScaler():SignalProcessor()
{
    setOutputNum(1);
    enableHelper(1,1,0);
}

void SignalScaler::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat,int counter){
    QVector<double> res=dat.at(0);
    double scale=doubdat.at(0);
    int i=0;
    while(i<res.count()){
        res.replace(i,res.at(i)*scale);
        i=i+1;
    }

    output_collection.at(0)->feedData(res,counter);
}

SignalScalerProvider::SignalScalerProvider(PVisual *pv){
    PV=pv;
}

QString SignalScalerProvider::getName(){
    return "SignalScale";
}

ProcessGraphics* SignalScalerProvider::newInstance(QString text){

     SignalScaler* sf=new SignalScaler();
     ProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,1,1,1,0,0,0,PV,this);
     return pg;

}
