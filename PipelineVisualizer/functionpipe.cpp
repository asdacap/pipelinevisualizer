#include "functionpipe.h"
#include <iostream>

FunctionPipe::FunctionPipe(double (*funct)(double)){
    thefunction=funct;
    setOutputNum(1);
}

void FunctionPipe::feedData(QVector<double> dat, int counter,int channel){
    QVector<double> res(dat.count());
    int i=0;
    while(i<res.count()){
        double ans=thefunction(dat.at(i));

        res.replace(i,ans);
        i=i+1;
    }

    output_collection.at(0)->feedData(res,counter);
}
