#include "integerdivide.h"

IntegerDivide::IntegerDivide()
{
    setDoubleOutputNum(2);
    enableHelper(0,2,0);
}

void IntegerDivide::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    int top=(int)doubdat.at(0);
    int bottomm=(int)doubdat.at(1);
    double_output_collection.at(0)->feedDoubleData((double)(top/bottomm),counter);
    double_output_collection.at(1)->feedDoubleData((double)(top%bottomm),counter);
}
