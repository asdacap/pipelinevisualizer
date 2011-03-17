#include "doublegenerator.h"

DoubleGenerator::DoubleGenerator(double val)
{
    cdat=0;
    setDoubleOutputNum(1);
    setValue(val);
}

void DoubleGenerator::setValue(double val){
    cdat=val;
}

double DoubleGenerator::getValue(){
    return cdat;
}

void DoubleGenerator::feedData(QVector<double> dat, int counter, int channel){
    double_output_collection.at(0)->feedDoubleData(getValue(),counter);
}
