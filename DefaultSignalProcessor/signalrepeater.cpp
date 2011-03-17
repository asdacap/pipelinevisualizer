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

#include "signalrepeater.h"

SignalRepeater::SignalRepeater()
{
    setOutputNum(1);
    enableHelper(1,1,0);
}

void SignalRepeater::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> thedata=dat.at(0);
    double thesize=doubdat.at(0);
    QVector<double> targetdata(thedata.count()*thesize);
    int i=0;
    while(i<targetdata.count()){
        if(i<thedata.count()){
            targetdata.replace(i,thedata.at(i));
        }else{
            targetdata.replace(i,thedata.at(i%thedata.count()));
        }
        i=i+1;
    }
    output_collection.at(0)->feedData(targetdata,counter);
}
