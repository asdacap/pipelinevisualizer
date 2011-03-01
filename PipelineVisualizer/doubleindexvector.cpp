#include "doubleindexvector.h"

DoubleIndexVector::DoubleIndexVector(QVector<double> dat){
    data=dat;
}

QVector<double> DoubleIndexVector::getData(){
    return data;
}

double CubicInterpolate(double y0,double y1,double y2,double y3,double mu){
    double a0,a1,a2,a3,mu2;

    mu2=mu*mu;
    a0=y3-y2-y0+y1;
    a1=y0-y1-a0;
    a2=y2-y0;
    a3=y1;

    double ret=a0*mu*mu2+a1*mu2+a2*mu+a3;
    return ret;

}

double DoubleIndexVector::at(double index){
    QVector<double> currentVect(data);
    int smindex=(int)index;
    if(smindex>index)smindex=smindex-1;
    if((double)smindex==index){
        return currentVect.at(smindex);
    }
    int larindex=smindex+1;
    if(currentVect.count()<=larindex)return 0;
    double div=index-smindex;

    double y1=smindex-1;
    if(y1<0)y1=0;
    double y2=smindex;
    double y3=smindex+1;
    double y4=smindex+2;
    if(y4>=currentVect.count())y4=y3;

    y1=currentVect.at(y1);
    y2=currentVect.at(y2);
    y3=currentVect.at(y3);
    y4=currentVect.at(y4);

    return CubicInterpolate(y1,y2,y3,y4,div);
}
