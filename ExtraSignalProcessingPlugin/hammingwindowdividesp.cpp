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

#include "hammingwindowdividesp.h"
#include "processgraphics.h"
#include "cmath"
#include "widgetedprocessgraphics.h"
#define PI 3.142857142857143

HammingWindowDivideSP::HammingWindowDivideSP()
{
    setOutputNum(1);
    enableHelper(1,0,0);
}

void HammingWindowDivideSP::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> data=dat.at(0);
    QVector<double> res(data.count());
    int i=0;
    while(i<res.count()){
        double cur=0.54-0.42*std::cos(2*PI*double(i)/res.count());
        res.replace(i,data.at(i)/cur);
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}

HammingWindowDivideSPProvider::HammingWindowDivideSPProvider(PVisual *pv):PipeProcessGraphicsProvider(pv){
    PV=pv;
}

ProcessGraphics* HammingWindowDivideSPProvider::newInstance(QString name){
    HammingWindowDivideSP* sp=new HammingWindowDivideSP();
    return new WidgetedProcessGraphics(sp,name,1,1,0,0,0,0,PV,this);
}

QString HammingWindowDivideSPProvider::getName(){
    return "HammingWindowDivideSP";
}
