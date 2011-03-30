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
#include "signaldifferentation.h"

SignalDifferentation::SignalDifferentation()
{
    setOutputNum(1);
    enableHelper(1,0,0);
}

void SignalDifferentation::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());
    int i=1;
    res.replace(0,dat.at(0));
    while(i<dat.count()-1){
        res.replace(i,dat.at(i)-dat.at(i-1));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
