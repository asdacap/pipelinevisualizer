#include "doubleisequal.h"

DoubleIsEqual::DoubleIsEqual()
{
    setBoolOutputNum(1);
    enableHelper(0,2,0);
}

void DoubleIsEqual::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    double d1=doubdat.at(0);
    double d2=doubdat.at(1);
    bool_output_collection.at(0)->feedBoolData(d1>d2,counter);

}
