/*
    Copyright 2010-2011 Muhd Amirul Ashraf <asdacap@gmail.com>

    This file is part of PipelineVisualizer.

    PipelineVisualizer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation.

    PipelineVisualizer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PipelineVisualizer.  If not, see <http://www.gnu.org/licenses/>.

*/

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
