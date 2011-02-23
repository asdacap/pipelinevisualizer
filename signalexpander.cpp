#include "signalexpander.h"
#include "doubleindexvector.h"

SignalExpander::SignalExpander()
{
    setOutputNum(1);
    enableHelper(1,2,1);
}

void SignalExpander::feedData(QVector<QVector<double> > datar, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat=datar.at(0);
    double ratio=doubdat.at(0);
    double offset=doubdat.at(1);
    bool reduce=booldat.at(0);

    DoubleIndexVector iv(dat);

    double tratio=ratio;
    QVector<double> scaled(dat.count()*tratio);

    int newlength=dat.count()*tratio;
    int i=0;
    while(i<newlength){
        double wantedIndex=i*(1/tratio);
        double val=iv.at(wantedIndex);
        scaled.replace(i,val);
        i=i+1;
    }

    if(!reduce){
        output_collection.at(0)->feedData(scaled,counter);
        return;
    }

    QVector<double> res(dat.count(),0);
    i=(int)offset;
    int ci=0;
    if(i<0){
        ci=-i;
        i=0;
    }
    while(i<res.count() && ci<scaled.count() ){
        res.replace(i,scaled.at(ci));
        i=i+1;
        ci=ci+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
