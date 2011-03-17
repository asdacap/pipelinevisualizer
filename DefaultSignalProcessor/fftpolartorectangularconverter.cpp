#include "fftpolartorectangularconverter.h"
#include "QVariant"
#include "cmath"
#include <iostream>
#define PI 3.142857142857143

FFTPolarToRectangularConverter::FFTPolarToRectangularConverter()
{
    setOutputNum(2);
    enableHelper(2,0,0);
}

void FFTPolarToRectangularConverter::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> magnitude=dat.at(0);
    QVector<double> phase=dat.at(1);

    QVector<double>* magnitudedat=&magnitude;
    QVector<double>* phasedat=&phase;
    if(magnitudedat->count()==phasedat->count()){

    }else{
        debugMessage("Incorrect length in polar-rectangular converter");

        int diffcount=magnitudedat->count()-phasedat->count();
        if(diffcount>0){
            magnitudedat->remove(magnitudedat->count()-diffcount-1,diffcount);
        }else{
            phasedat->remove(phasedat->count()+diffcount-1,-diffcount);
        }

        debugMessage("magnitude "+QVariant(magnitudedat->count()).toString());
        debugMessage("phase "+QVariant(phasedat->count()).toString());
    }

    int length=magnitudedat->count();

    QVector<double> temp(length);
    int i=0;
    while(i<length){
        temp.replace(i,magnitudedat->at(i)*cos(phasedat->at(i)));
        i=i+1;
    }
    output_collection.at(0)->feedData(temp,counter);


    i=0;
    while(i<length){
        temp.replace(i,magnitudedat->at(i)*sin(phasedat->at(i)));
        i=i+1;
    }
    output_collection.at(1)->feedData(temp,counter);
}
