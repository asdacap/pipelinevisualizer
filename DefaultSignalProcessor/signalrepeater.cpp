#include "signalrepeater.h"

SignalRepeater::SignalRepeater()
{
    setOutputNum(1);
    enableHelper(1,1,0);
}

void SignalRepeater::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> thedata=dat.at(0);
    double thesize=doubdat.at(0);
    QVector<double> targetdata(thedata.count()*thesize);
    int i=0;
    while(i<targetdata.count()){
        if(i<thedata.count()){
            targetdata.replace(i,thedata.at(i));
        }else{
            targetdata.replace(i,thedata.at(i%thedata.count()));
        }
        i=i+1;
    }
    output_collection.at(0)->feedData(targetdata,counter);
}
