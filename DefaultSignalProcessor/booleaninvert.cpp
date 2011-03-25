#include "booleaninvert.h"

BooleanInvert::BooleanInvert()
{
    setBoolOutputNum(1);
}

void BooleanInvert::feedBoolData(bool dat, int counter, int channel){
    bool_output_collection.at(0)->feedBoolData(dat,counter);
}
