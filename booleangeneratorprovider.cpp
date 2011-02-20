#include "booleangeneratorprovider.h"
#include "QInputDialog"
#include <iostream>
#include "defaultprocessgraphics.h"

BooleanGeneratorProvider::BooleanGeneratorProvider(MainWindow *mw, PVisual *pv){
    MW=mw;
    PV=pv;
}

QString BooleanGeneratorProvider::getName(){
    return "Boolean generator";
}

ProcessGraphics* BooleanGeneratorProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         BooleanGenerator* sf=new BooleanGenerator();
         MW->registerVariable(sf,text);
         ProcessGraphics* pg=new DefaultProcessGraphics(sf,text,1,0,0,0,0,1,PV);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
