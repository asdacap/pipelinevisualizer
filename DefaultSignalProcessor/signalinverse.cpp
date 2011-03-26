#include "signalinverse.h"

SignalInverse::SignalInverse()
{
    setOutputNum(1);
}

void SignalInverse::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res=dat;
    int i=0;
    while(i<res.count()){
        res.replace(i,1/dat.at(i));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
