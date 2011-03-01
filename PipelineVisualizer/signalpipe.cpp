#include "signalpipe.h"

SignalPipe::SignalPipe()
{
    setOutputNum(1);
}

void SignalPipe::feedData(QVector<double> dat, int counter, int channel){
    output_collection.at(0)->feedData(dat,counter);
}
