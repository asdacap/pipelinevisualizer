#include "signalminus.h"

SignalMinus::SignalMinus()
{
    setOutputNum(1);
    enableHelper(2,0,0);
}

void SignalMinus::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> sig1=dat.at(0);
    QVector<double> sig2=dat.at(1);
    int length=sig1.count();
    if(sig2.count()<length)length=sig2.count();
    QVector<double> res(length);
    int i=0;
    while(i<length){
        res.replace(i,sig1.at(i)-sig2.at(i));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
