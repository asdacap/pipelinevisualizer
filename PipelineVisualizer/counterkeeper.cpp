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

#include "counterkeeper.h"
#include <iostream>

CounterKeeper::CounterKeeper(int l)
{
    clength=l;
    int i=0;
    while(i<clength){
        dat.append(new QList<KeyValPair>());
        i=i+1;
    }
}

bool CounterKeeper::isAvail(int index, int counter){
    if(index>=clength){
        std::cout<<"Invalid index"<<std::endl;
        return false;
    }
    QList<KeyValPair>* row=dat.at(index);
    int i=0;
    while(i<row->count()){
        if(row->at(i).counter==counter){
            return true;
        }
        i=i+1;
    }
    return false;
}

int CounterKeeper::theLength(){
    return clength;
}

void CounterKeeper::addKey(int index, int counter, void *data){
    if(index>=clength)return;
    if(isAvail(index,counter)){
        std::cout<<"avail"<<std::endl;
        return;
    }

    KeyValPair val;
    val.counter=counter;
    val.data=data;

    dat.at(index)->append(val);

    QList<KeyValPair>* check=dat.at(index);
    int i=0;
    while(i<check->count()){
        if(counter-check->at(i).counter>10){
            std::cout<<"Counter error, overfowing data at counter "<<counter<<std::endl;
            delete check->at(i).data;
            check->removeAt(i);
            continue;
        }
        i=i+1;
    }
}

void* CounterKeeper::getObject(int index, int counter){
    QList<KeyValPair>* col=dat.at(index);
    int i=0;
    while(i<col->count()){
        if(col->at(i).counter==counter){
            void* dat=col->at(i).data;
            col->removeAt(i);
            return dat;
        }
        i=i+1;
    }
    std::cout<<"This should not happen! Error on counter!"<<std::endl;
    return 0;
}

bool CounterKeeper::isAvail(int counter){
    int i=0;
    while(i<clength){
        if(!isAvail(i,counter)){
            return false;
        }
        i=i+1;
    }
    void** dlist=new void*[clength];
    i=0;
    while(i<clength){
        dlist[i]=getObject(i,counter);
        i=i+1;
    }
    KeyValPairComp comp;
    comp.counter=counter;
    comp.data=dlist;
    comleteDat.append(comp);
    return true;
}

void** CounterKeeper::getObject(int counter){
    int i=0;
    while(i<comleteDat.count()){
        if(comleteDat.at(i).counter==counter){
            void** dat=comleteDat.at(i).data;
            comleteDat.removeAt(i);
            return dat;
        }

        i=i+1;

    }
    std::cout<<"This should not happen! Error on counter! getobject"<<std::endl;
    return 0;
}
