#include "blocklengthsender.h"

BlockLengthSender::BlockLengthSender()
{
    setDoubleOutputNum(1);

}

void BlockLengthSender::feedData(QVector<double> dat, int counter, int channel){
    double_output_collection.at(0)->feedDoubleData((double)dat.count(),counter);
}
