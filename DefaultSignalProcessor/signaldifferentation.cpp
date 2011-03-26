#include "signaldifferentation.h"

SignalDifferentation::SignalDifferentation()
{
    setOutputNum(1);
    enableHelper(1,0,0);
}

void SignalDifferentation::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());
    int i=1;
    res.replace(0,dat.at(0));
    while(i<dat.count()-1){
        res.replace(i,dat.at(i)-dat.at(i-1));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
