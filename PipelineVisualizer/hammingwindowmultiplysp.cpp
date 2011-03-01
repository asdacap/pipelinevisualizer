#include "hammingwindowmultiplysp.h"
#include "processgraphics.h"
#include "cmath"
#include "widgetedprocessgraphics.h"
#define PI 3.142857142857143

HammingWindowMultiplySP::HammingWindowMultiplySP()
{
    setOutputNum(1);
    enableHelper(1,0,0);
}

void HammingWindowMultiplySP::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> data=dat.at(0);
    QVector<double> res(data.count());
    int i=0;
    while(i<res.count()){
        double cur=0.54-0.42*std::cos(2*PI*double(i)/res.count());
        res.replace(i,data.at(i)*cur);
        i=i+1;
    }
    output_collection.at(0)->feedData(res,counter);
}

HammingWindowMultiplySPProvider::HammingWindowMultiplySPProvider(PVisual *pv){
    PV=pv;
}

ProcessGraphics* HammingWindowMultiplySPProvider::newInstance(QString name){
    HammingWindowMultiplySP* sp=new HammingWindowMultiplySP();
    return new WidgetedProcessGraphics(sp,name,1,1,0,0,0,0,PV,this);
}

QString HammingWindowMultiplySPProvider::getName(){
    return "HammingWindowMultiplySP";
}
