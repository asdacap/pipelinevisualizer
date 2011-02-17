#ifndef UTIL_H
#define UTIL_H
#include <Qt>
#include <QVector>
#include "constSetting.h"
void inline intToDouble(qint16* data,long len,double* conv){
    long i=0;
    while(i<len){
        conv[i]=(double)data[i];
        i=i+1;
    }
}

void inline charToDouble(const char* data,long len,double* conv){
    long i=0;
    while(i<len){
        conv[i]=(double)data[i];
        i=i+1;
    }
}

int fftSize();

double oneifzero(double dat);
QVector<QVector<double> > indexVal(QVector<QVector<double> > inp);
QVector<double> getPeak(QVector<double> dat);
QVector<double> lowerBound(QVector<double> dat);
QVector<double> topOnly(QVector<double> dat);
QVector<double> harmonicsAdder(QVector<double> dat);
QVector<QVector<double> > readyGraph(QVector<QVector<double> > inp);
QVector<double> fftherzindex(QVector<double> dat);
double oneifnotzero(double dat);
QVector<double> putZeroAtEnd(QVector<double> dat);
QVector<QVector<double> > subtractIt(QVector<QVector<double> > dat);
QVector<double> phaseUnmask(QVector<double> dat);
QVector<QVector<double> > concatenate(QVector<QVector<double> > input);
double inverse(double);

QVector<double> harmonicBoost(QVector<double> dat);
QVector<double> unIntegrate(QVector<double> dat);

#endif // UTIL_H
