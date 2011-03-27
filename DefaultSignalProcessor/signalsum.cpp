#include "signalsum.h"

SignalSum::SignalSum()
{
    setDoubleOutputNum(1);
}

void SignalSum::feedData(QVector<double> dat, int counter, int channel){
    int i=0;
    double current=0;
    while(i<dat.count()){
        current=current+dat.at(i);
        i=i+1;
    }
    double_output_collection.at(0)->feedDoubleData(current,counter);
}
