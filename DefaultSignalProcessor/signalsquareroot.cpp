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
#include "signalsquareroot.h"
#include "cmath"

SignalSquareRoot::SignalSquareRoot()
{
    setOutputNum(1);
}

void SignalSquareRoot::feedData(QVector<double> dat, int counter, int channel){
    QVector<double> res(dat.count());

    int i=0;
    while(i<dat.count()){
        res.replace(i,sqrt(dat.at(i)));
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}
