#include "doubleminus.h"

DoubleMinus::DoubleMinus()
{

    setDoubleOutputNum(1);
    enableHelper(0,2,0);
}

void DoubleMinus::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    double d1=doubdat.at(0);
    double d2=doubdat.at(1);
    double_output_collection.at(0)->feedDoubleData(d1-d2,counter);
}
