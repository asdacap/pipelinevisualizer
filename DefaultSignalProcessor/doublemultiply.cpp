#include "doublemultiply.h"

DoubleMultiply::DoubleMultiply()
{
    setDoubleOutputNum(1);
    enableHelper(0,2,0);
}

void DoubleMultiply::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    double dat1=doubdat.at(0);
    double dat2=doubdat.at(1);
    double_output_collection.at(0)->feedDoubleData(dat1*dat2,counter);
}
