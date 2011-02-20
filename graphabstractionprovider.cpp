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


ProcessGraphics* GraphAbstractionProvider::newInstance(QString name){
    QString text=name;
    GraphAbstraction* sf=new GraphAbstraction(text);
    SimpleLineGraph* slg=new SimpleLineGraph();
    slg->setGraphData(sf);
    WidgetedProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,2,1,0,0,0,0,pv,this,slg,QRect(0,0,400,400));
    return pg;
}
