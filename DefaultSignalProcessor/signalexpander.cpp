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

#include "signalexpander.h"
#include "doubleindexvector.h"

SignalExpander::SignalExpander()
{
    setOutputNum(1);
    enableHelper(1,2,1);
}

void SignalExpander::feedData(QVector<QVector<double> > datar, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat=datar.at(0);
    double ratio=doubdat.at(0);
    double offset=doubdat.at(1);
    bool reduce=booldat.at(0);

    DoubleIndexVector iv(dat);

    double tratio=ratio;
    QVector<double> scaled(dat.count()*tratio);

    int newlength=dat.count()*tratio;
    int i=0;
    while(i<newlength){
        double wantedIndex=i*(1/tratio);
        double val=iv.at(wantedIndex);
        scaled.replace(i,val);
        i=i+1;
    }

    if(!reduce){
        output_collection.at(0)->feedData(scaled,counter);
        return;
    }

    QVector<double> res(dat.count(),0);
    i=(int)offset;
    int ci=0;
    if(i<0){
        ci=-i;
        i=0;
    }
    while(i<res.count() && ci<scaled.count() ){
        res.replace(i,scaled.at(ci));
        i=i+1;
        ci=ci+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
