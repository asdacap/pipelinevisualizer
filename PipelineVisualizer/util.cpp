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

#include "util.h"
#include <iostream>

double inverse(double dat){
    if(dat==0)return 0;
    return 1/dat;
}

double oneifzero(double dat){

    if(dat==0){
        return 1;
    }else{
    return dat;
}
}

double oneifnotzero(double dat){
    if(dat!=0){
        return 1;
    }else{
    return dat;
}
}

int fftSize(){
    return (freqSize()/2)+1;
}

QVector<double> harmonicBoost(QVector<double> dat){
    QVector<double> res(dat.count());
    double fundamental=dat.at(0);
    int i=0;
    while(i<dat.count()){
        res.replace(i,dat.at(i)/(fundamental/i));
        i=i+1;
    }
    return res;
}

QVector<QVector<double> > indexVal(QVector<QVector<double> > inp){
    QVector<double> res;
    res.append(inp.at(0).at(inp.at(1).at(0)));
    QVector<QVector<double> > ret;
    ret.append(res);
    return ret;
}


QVector<QVector<double> > readyGraph(QVector<QVector<double> > inp){

    QVector<double> res1;
    QVector<double> res2;
    QVector<double> dat=inp.at(0);
    int i=0;
    while(i<dat.count()){
        if(dat.at(i)>0){
            res1.append(dat.at(i));
            res2.append(i);
        }

        i=i+1;
    }

    QVector<QVector<double> > ret;
    ret.append(res1);
    ret.append(res2);
    return ret;
}

QVector<double> fftherzindex(QVector<double> dat){
    QVector<double> res(dat.count());

    int i=0;
    while(i<dat.count()){
        res.replace(i,freqToHerz(i));
        i=i+1;
    }

    return res;
}

QVector<double> getPeak(QVector<double> dat){
    QVector<double> resul(dat.count());
    int i=0;
    while(i<dat.count()){
        if(i==0){
            resul.replace(i,0);
        }else if(i==(dat.count()-1)){
            resul.replace(i,0);
        }else if(dat.at(i-1)<=dat.at(i) && dat.at(i+1)<dat.at(i)){
            resul.replace(i,dat.at(i));
        }else{
            resul.replace(i,0);
        }
        i=i+1;
    }
    return resul;
}

int lowerbound=0;

QVector<double> lowerBound(QVector<double> dat){
    QVector<double> resul(dat.count());
    int i=0;
    while(i<dat.count()){
        if(dat.at(i)<lowerbound){
            resul.replace(i,0);
        }else{
            resul.replace(i,dat.at(i)-lowerbound);
        }
        i=i+1;
    }
    return resul;
}

int topWhat=10;

int highestIndex(QVector<double> dat){
    int i=0;
    int curind=0;
    while(i<dat.count()){
        if(dat.at(i)>dat.at(curind)){
            curind=i;
        }
        i=i+1;
    }
    return curind;
}

QVector<double> topOnly(QVector<double> dat){
    QVector<double> temp(dat);
    QVector<double> res(dat.count(),0);

    int i=0;
    while(i<topWhat){
        int index=highestIndex(temp);
        temp.replace(index,0);
        res.replace(index,dat.at(index));
        i=i+1;
    }
    return res;
}

int tolerance=1;

QVector<double> harmonicsAdder(QVector<double> dat){
    QVector<double> res(dat);

    int i=dat.count()-1;
    while(i>=0){
        if(dat.at(i)!=0){
            int i2=0;
            while(i2<i){
                if(dat.at(i2)!=0){
                    if(i%i2<tolerance || i2-(i%i2)<tolerance){
                        int dif=i/i2;
                        int theind=i-dif;
                        bool isok=true;
                        while(theind>i){
                            if(dat.at(theind)==0){
                                isok=false;
                                break;
                            }
                            theind=theind-dif;
                        }
                        if(isok){
                            res.replace(i2,res.at(i2)+dat.at(i));
                        }
                    }
                }

                i2=i2+1;
            }
        }
        i=i-1;
    }

    return res;
}

QVector<double> putZeroAtEnd(QVector<double> dat){
    QVector<double> res(dat);
    res.replace(0,0);
    res.replace(res.count()-1,0);
    return res;
}

QVector<QVector<double> > subtractIt(QVector<QVector<double> > dat){
    QVector<double> dat1=dat[0];
    QVector<double> dat2=dat[1];
    int thelength=dat1.count();
    if(dat2.count()<dat1.count()){
        thelength=dat2.count();
    }
    QVector<double> res(thelength);
    int i=0;
    while(i<thelength){
        double newval=dat1[i]-dat2[i];
        if(newval<0){
            newval=0;
        }
        res.replace(i,newval);
        i=i+1;
    }

    QVector<QVector<double> > realres;
    realres.append(res);
    return realres;
}

#define PI 3.1428571428

QVector<double> phaseUnmask(QVector<double> dat){
    QVector<double> res(dat);
    double cur=dat.at(0);
    int i=1;
    while(i<dat.count()){
        double dif=dat.at(i)-dat.at(i-1);
        if(dif>PI || dif<-PI){
            dif=0;
        }
        cur=cur+dif;
        res.replace(i,cur);

        i=i+1;
    }
    return res;
}

QVector<QVector<double> > concatenate(QVector<QVector<double> > input){
    int indl=input.count();
    int totallenth=0;
    int i=0;
    while(i<indl){
        totallenth=totallenth+input.at(i).count();
        i=i+1;
    }
    QVector<double> res(totallenth);

    i=0;
    int ci=0;
    while(i<indl){
        int i2=0;
        QVector<double> cinp=input.at(i);
        while(i2<cinp.count()){
            res.replace(ci,cinp.at(i2));
            i2=i2+1;
            ci=ci+1;
        }
        i=i+1;
    }

    QVector<QVector<double> > theret;
    theret.append(res);
    return theret;
}

QVector<double> unIntegrate(QVector<double> dat){
    QVector<double> res(dat.count(),0);
    int i=0;
    while(i<dat.count()-1){
        res.replace(i,dat.at(i+1)-dat.at(i));
        i=i+1;
    }
    return res;
}
