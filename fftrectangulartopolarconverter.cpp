#include "fftrectangulartopolarconverter.h"
#include "cmath"
#include <iostream>
#define PI 3.142857142857143

FFTRectangularToPolarConverter::FFTRectangularToPolarConverter()
{
    setOutputNum(2);
    enableHelper(2,0,0);
}

void FFTRectangularToPolarConverter::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> realpart=dat.at(0);
    QVector<double> imaginarypart=dat.at(1);
    QVector<double>* realdat=&realpart;
    QVector<double>* imagdat=&imaginarypart;
    if(realdat->count()==imagdat->count()){

    }else{
        std::cout<<"Incorrect length in rectangular-polar converter"<<std::endl;
    }

    int length=realdat->count();
    QVector<double> magnitudeData(length);
    int i=0;
    while(i<length){
        magnitudeData.replace(i,sqrt((realdat->at(i) * realdat->at(i))+(imagdat->at(i) * imagdat->at(i))));
        i=i+1;
    }
    output_collection.at(0)->feedData(magnitudeData,counter);

    double* magholder=new double[length];
    QVector<double> phaseData(length);
    i=0;
    while(i<length){
        if(realdat->at(i)==0){

            if(imagdat->at(i) < 0){
                magholder[i]=-PI;
            }else{
                magholder[i]=PI;
            }
            i=i+1;
            continue;
        }
        magholder[i]=atan(imagdat->at(i)/realdat->at(i));
        if(realdat->at(i) < 0){
            if(imagdat->at(i) < 0){
                magholder[i]=magholder[i]-PI;
            }else{
                magholder[i]=magholder[i]+PI;
            }

        }
        phaseData.replace(i,magholder[i]);
        i=i+1;
    }
    output_collection.at(1)->feedData(phaseData,counter);
    delete []magholder;

}
