#include "signalindex.h"

SignalIndex::SignalIndex()
{
    setOutputNum(1);
}

void SignalIndex::feedData(QVector<double> dat, int counter, int channel){
    int i=0;
    QVector<double> theindex(dat.count());
    while(i<dat.count()){
        theindex.replace(i,i);
        i=i+1;
    }
    output_collection.at(0)->feedData(theindex,counter);
}
