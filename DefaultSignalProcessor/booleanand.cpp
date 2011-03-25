#include "booleanand.h"

BooleanAnd::BooleanAnd()
{
    setBoolOutputNum(1);
    enableHelper(0,0,2);
}

void BooleanAnd::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    bool b1=booldat.at(0);
    bool b2=booldat.at(1);
    bool_output_collection.at(0)->feedBoolData(b1==b2,counter);
}
