#include "plainsignalpipe.h"

PlainSignalPipe::PlainSignalPipe()
{
    setOutputNum(1);
}

void PlainSignalPipe::feedData(QVector<double> dat, int counter, int channel){
    output_collection.at(0)->feedData(dat,counter);
}
