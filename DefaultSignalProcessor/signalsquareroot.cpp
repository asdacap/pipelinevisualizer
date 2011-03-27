#include "signalsquareroot.h"
#include "cmath"

SignalSquareRoot::SignalSquareRoot()
{
    setOutputNum(1);
}

void SignalSquareRoot::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());

    int i=0;
    while(i<dat.count()){
        res.replace(i,sqrt(dat.at(i)));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
