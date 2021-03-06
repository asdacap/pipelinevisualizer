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
#include "signalmedian.h"
#include "QtAlgorithms"

SignalMedian::SignalMedian()
{
    setDoubleOutputNum(1);
}

void SignalMedian::feedData(QVector<double> dat, int counter, int channel){
    qSort(dat);
    int i=dat.count()%2;
    if(i!=0){
        double_output_collection.at(0)->feedDoubleData(dat.at(dat.count()/2),counter);
    }else{
        double ddat=dat.at(dat.count()/2);
        double ddat2=dat.at((dat.count()/2)+1);
        double_output_collection.at(0)->feedDoubleData((ddat+ddat2)/2,counter);
    }
}
