#include "pinknoiseremover.h"

PinkNoiseRemover::PinkNoiseRemover()
{
    setOutputNum(1);
    enableHelper(1,1,0);
}

void PinkNoiseRemover::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> data=dat.at(0);
    double thresshold=doubdat.at(0);
    int endbound=(int)data.count()*thresshold;
    QVector<double> ret=data;
    int i=0;
    while(i<endbound){
        ret.replace(i,data.at(i)*(i+1)/endbound);
        i=i+1;
    }
    output_collection.at(0)->feedData(ret,counter);
}
