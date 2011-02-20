#include "booleangeneratorprovider.h"
#include "QInputDialog"
#include <iostream>
#include "widgetedprocessgraphics.h"
#include "QCheckBox"

BooleanGeneratorProvider::BooleanGeneratorProvider( PVisual *pv){
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
         QCheckBox* cbox=new QCheckBox(text,0);
         cbox->setChecked(sf->getValue());
         QObject::connect(cbox,SIGNAL(toggled(bool)),sf,SLOT(setValue(bool)));
         ProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,1,0,0,0,0,1,PV,cbox,QRect(0,0,
                                                                                           cbox->fontMetrics().width(text)+20
                                                                                           ,15));
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
