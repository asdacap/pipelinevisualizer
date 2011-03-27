#include "signaldeviation.h"

SignalDeviation::SignalDeviation()
{
    setDoubleOutputNum(1);
}

void SignalDeviation::feedData(QVector<double> dat, int counter, int channel){
    int i=0;
    double current=0;
    while(i<dat.count()){
        current=current+dat.at(i);
        i=i+1;
    }
    double mean=current/dat.count();
    current=0;
    i=0;
    while(i<dat.count()){
        double cur=dat.at(0)-mean;
        cur=cur*cur;
        current=current+cur;
        i=i+1;
    }
    double_output_collection.at(0)->feedDoubleData(current/mean,counter);
}
