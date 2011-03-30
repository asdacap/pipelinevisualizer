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
#include "signalminus.h"

SignalMinus::SignalMinus()
{
    setOutputNum(1);
    enableHelper(2,0,0);
}

void SignalMinus::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> sig1=dat.at(0);
    QVector<double> sig2=dat.at(1);
    int length=sig1.count();
    if(sig2.count()<length)length=sig2.count();
    QVector<double> res(length);
    int i=0;
    while(i<length){
        res.replace(i,sig1.at(i)-sig2.at(i));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
