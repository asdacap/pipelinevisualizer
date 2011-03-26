#include "signaldifferentation.h"

SignalDifferentation::SignalDifferentation()
{
    setOutputNum(1);
    enableHelper(1,0,0);
}

void SignalDifferentation::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count()-1);
    int i=0;
    while(i<dat.count()-1){
        res.replace(i,dat.at(i+1)-dat.at(i));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
