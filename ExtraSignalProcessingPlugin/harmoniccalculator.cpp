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

#include "harmoniccalculator.h"
#include "constSetting.h"

HarmonicCalculator::HarmonicCalculator()
{

    interval=herzToFreq(1);
    setOutputNum(1);
    enableHelper(1,2,0);
}

double HarmonicCalculator::sumIt(DoubleIndexVector* ind,double index){

    double startcalc=herzToFreq(50);
    double endcalc=herzToFreq(5000);

    int maxcalc=20;

    double i=0;
    double cur=0;
    double div=1;
    int counter=0;
    int count=ind->data.count();
    while(i<count && counter<maxcalc){
        if(i>startcalc && i<endcalc){
            cur=cur+ind->at(i);
            if(i!=0){
            double thedif=ind->at(i)-ind->at(i-1);
            if(thedif<0)thedif=thedif*-1;
            div=div+thedif;
            }
            counter=counter+1;
        }
        i=i+index;
    }
    return cur/div;
}

void HarmonicCalculator::feedData(QVector<QVector<double> > datat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat=datat.at(0);
    double harmmin=doubdat.at(0);
    double harmmax=doubdat.at(1);

    DoubleIndexVector iv(dat);
    QVector<double> ret;

    double i=0;
    while(i<harmmax){
        if(i>harmmin&&i<harmmax){
            ret.append(sumIt(&iv,i));
        }else{
            ret.append(0);
        }
        i=i+interval;
    }

    output_collection.at(0)->feedData(ret,counter);
}

