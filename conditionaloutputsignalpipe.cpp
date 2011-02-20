#include "conditionaloutputsignalpipe.h"
#include <QInputDialog>
#include <iostream>
#include "defaultprocessgraphics.h"

ConditionalOutputSignalPipe::ConditionalOutputSignalPipe():SignalProcessor()
{
    setOutputNum(2);
    enableHelper(1,0,1);
}

void ConditionalOutputSignalPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat1=dat.at(0);
    bool thevalue=booldat.at(0);
    if(thevalue){
        output_collection.at(0)->feedData(dat1,counter);
    }else{
        output_collection.at(1)->feedData(dat1,counter);
    }
}

ConditionalOutputSignalPipeProvider::ConditionalOutputSignalPipeProvider(PVisual *pv){
    PV=pv;
}

QString ConditionalOutputSignalPipeProvider::getName(){
    return "Conditional output signal pipe";
}

ProcessGraphics* ConditionalOutputSignalPipeProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         ConditionalOutputSignalPipe* sf=new ConditionalOutputSignalPipe();

         ProcessGraphics* pg=new DefaultProcessGraphics(sf,text,1,2,0,0,1,0,PV,this);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
