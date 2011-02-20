#include "graphabstractionprovider.h"
#include "widgetedprocessgraphics.h"
#include "QInputDialog"
#include <iostream>

GraphAbstractionProvider::GraphAbstractionProvider(PVisual* pvs){

    pv=pvs;
}

QString GraphAbstractionProvider::getName(){
    return "Graph";
}

ProcessGraphics* GraphAbstractionProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         GraphAbstraction* sf=new GraphAbstraction(text);
         SimpleLineGraph* slg=new SimpleLineGraph();
         slg->setGraphData(sf);
         WidgetedProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,2,1,0,0,0,0,pv,this,slg,QRect(0,0,400,400));
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}

