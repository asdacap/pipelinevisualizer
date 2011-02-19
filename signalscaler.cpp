#include "signalscaler.h"
#include "QInputDialog"
#include <iostream>

SignalScaler::SignalScaler():SignalProcessor()
{
    setOutputNum(1);
    enableHelper(1,1,0);
}

void SignalScaler::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat,int counter){
    QVector<double> res=dat.at(0);
    double scale=doubdat.at(0);
    int i=0;
    while(i<res.count()){
        res.replace(i,res.at(i)*scale);
        i=i+1;
    }

    output_collection.at(0)->feedData(res,counter);
}

SignalScalerProvider::SignalScalerProvider(PVisual *pv){
    PV=pv;
}

QString SignalScalerProvider::getName(){
    return "Signal Scale";
}

ProcessGraphics* SignalScalerProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         SignalScaler* sf=new SignalScaler();
         ProcessGraphics* pg=new ProcessGraphics(sf,text,1,1,1,0,0,0,PV);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
