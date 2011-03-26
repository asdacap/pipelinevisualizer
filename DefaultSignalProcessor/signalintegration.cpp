#include "signalintegration.h"

SignalIntegration::SignalIntegration()
{
    setOutputNum(1);
}

void SignalIntegration::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());
    int i=0;
    double dcounter=0;
    while(i<res.count()){
        dcounter=dcounter+dat.at(i);
        res.replace(i,dcounter);
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
