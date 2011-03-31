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

#include "conditionalinputsignalpipe.h"

ConditionalInputSignalPipe::ConditionalInputSignalPipe()
{
    setOutputNum(1);
    tempbol=false;

    dat1set=false;
    dat2set=false;
    bolset=false;
}

void ConditionalInputSignalPipe::feedBoolData(bool dat, int counter, int channel){
    if(currentCounter==counter){
        tempbol=dat;
        if(tempbol){
            if(!dat1set)return;
            output_collection.at(0)->feedData(datchan1,counter);
        }else{
            if(!dat2set)return;
            output_collection.at(0)->feedData(datchan2,counter);
        }
        dat1set=false;
        dat2set=false;
        bolset=false;
    }else{
        currentCounter=counter;
        tempbol=dat;
        bolset=true;
    }
}

void ConditionalInputSignalPipe::feedData(QVector<double> dat, int counter, int channel){
    if(currentCounter==counter){
        if(!bolset){
            if(channel==0){
                datchan1=dat;
                dat1set=true;
            }else{
                datchan2=dat;
                dat2set=true;
            }
        }else{
            if(tempbol){
                if(channel==0){
                    output_collection.at(0)->feedData(dat,counter);
                }
            }else{
                if(channel==1){
                    output_collection.at(0)->feedData(dat,counter);
                }
            }
        }
    }else{
        currentCounter=counter;
        if(channel==0){
            datchan1=dat;
            dat1set=true;
        }else{
            datchan2=dat;
            dat2set=true;
        }
    }
}

void ConditionalInputSignalPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat1=dat.at(0);
    QVector<double> dat2=dat.at(1);
    bool condition=booldat.at(0);
    if(condition){
        output_collection.at(0)->feedData(dat1,counter);
    }else{
        output_collection.at(0)->feedData(dat2,counter);
    }
}

