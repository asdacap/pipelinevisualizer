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

#include "graphabstraction.h"
#include <iostream>

GraphAbstraction::GraphAbstraction(QString cname):SignalProcessor(){
    locked=false;
    name=cname;
    setOutputNum(1);
    thekeeper=new CounterKeeper(2);
}

QString GraphAbstraction::getName()
{
    return name;
}


void GraphAbstraction::feedData(QVector<double> dat, int counter, int channel){
    if(locked)return;
    if(channel==0){
        QVector<double>* datp=new QVector<double>(dat);
        thekeeper->addKey(0,counter,datp);

        QVector<double> newdat(datp->count());
        int i=0;
        while(i<newdat.count()){
            newdat.replace(i,i);
            i=i+1;
        }
        output_collection.at(0)->feedData(newdat,counter);

    }else if(channel==1){
        QVector<double>* datp=new QVector<double>(dat);
        thekeeper->addKey(1,counter,datp);
    }else{
        debugMessage("Invalid data passed to graph feed data");
        return;
    }

    if(thekeeper->isAvail(counter)){
        void** truedata=thekeeper->getObject(counter);
        QVector<double>* daty=(QVector<double>*)truedata[0];
        QVector<double>* datx=(QVector<double>*)truedata[1];
        xdata=*datx;
        ydata=*daty;
        delete daty;
        delete datx;
    }
}

void GraphAbstraction::lock(){
    locked=true;
}

void GraphAbstraction::unlock(){
    locked=false;
}


