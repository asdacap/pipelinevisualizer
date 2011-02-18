#include "booleangenerator.h"

BooleanGenerator::BooleanGenerator()
{
    cdat=0;
    setDoubleOutputNum(1);
}

void BooleanGenerator::setValue(bool val){
    cdat=val;
}

bool BooleanGenerator::getValue(){
    return cdat;
}

void BooleanGenerator::feedData(QVector<double> dat, int counter, int channel){
    bool_output_collection.at(0)->feedBoolData(getValue(),counter);
}
