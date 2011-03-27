#include "signalmedian.h"
#include "QtAlgorithms"

SignalMedian::SignalMedian()
{
    setDoubleOutputNum(1);
}

void SignalMedian::feedData(QVector<double> dat, int counter, int channel){
    qSort(dat);
    int i=dat.count()%2;
    if(i!=0){
        double_output_collection.at(0)->feedDoubleData(dat.at(dat.count()/2),counter);
    }else{
        double ddat=dat.at(dat.count()/2);
        double ddat2=dat.at((dat.count()/2)+1);
        double_output_collection.at(0)->feedDoubleData((ddat+ddat2)/2,counter);
    }
}
