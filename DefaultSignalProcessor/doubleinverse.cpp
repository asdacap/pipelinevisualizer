#include "doubleinverse.h"

DoubleInverse::DoubleInverse()
{
    setDoubleOutputNum(1);
}

void DoubleInverse::feedDoubleData(double dat, int counter, int channel){
    double_output_collection.at(0)->feedDoubleData(1/dat,counter);
}
