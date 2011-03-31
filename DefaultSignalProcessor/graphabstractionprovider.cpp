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

#include "graphabstractionprovider.h"
#include "widgetedprocessgraphics.h"
#include "QInputDialog"
#include <iostream>

GraphAbstractionProvider::GraphAbstractionProvider(PVisual* pvs):PipeProcessGraphicsProvider(pvs){

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
