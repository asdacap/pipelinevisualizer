#include "signalintegration.h"

SignalIntegration::SignalIntegration()
{
    setOutputNum(1);
}

void SignalIntegration::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());
    int i=0;
    double counter=0;
    while(i<res.count()){
        counter=counter+dat.at(i);
        res.replace(i,counter);
        i=i+1;
    }
    return res;
}
