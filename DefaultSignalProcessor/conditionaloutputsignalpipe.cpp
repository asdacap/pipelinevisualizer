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

#include "conditionaloutputsignalpipe.h"

ConditionalOutputSignalPipe::ConditionalOutputSignalPipe():SignalProcessor()
{
    setOutputNum(2);
    enableHelper(1,0,1);
}

void ConditionalOutputSignalPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat1=dat.at(0);
    bool thevalue=booldat.at(0);
    if(thevalue){
        output_collection.at(0)->feedData(dat1,counter);
        //output_collection.at(1)->feedData(QVector<double>(dat1.count()),counter);
    }else{
        output_collection.at(1)->feedData(dat1,counter);
        //output_collection.at(0)->feedData(QVector<double>(dat1.count()),counter);
    }
}
