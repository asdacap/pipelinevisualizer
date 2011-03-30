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
#include "signaldeviation.h"

SignalDeviation::SignalDeviation()
{
    setDoubleOutputNum(1);
}

void SignalDeviation::feedData(QVector<double> dat, int counter, int channel){
    int i=0;
    double current=0;
    while(i<dat.count()){
        current=current+dat.at(i);
        i=i+1;
    }
    double mean=current/dat.count();
    current=0;
    i=0;
    while(i<dat.count()){
        double cur=dat.at(0)-mean;
        cur=cur*cur;
        current=current+cur;
        i=i+1;
    }
    double_output_collection.at(0)->feedDoubleData(current/mean,counter);
}
