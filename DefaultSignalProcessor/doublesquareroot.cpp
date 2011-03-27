#include "doublesquareroot.h"
#include "cmath"

DoubleSquareRoot::DoubleSquareRoot()
{
    setDoubleOutputNum(1);
}

void DoubleSquareRoot::feedDoubleData(double dat, int counter, int channel){

    double_output_collection.at(0)->feedDoubleData(sqrt(dat),counter);
}
