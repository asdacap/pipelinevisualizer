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

#include "pvisual.h"
#include "QVBoxLayout"
#include "QToolBar"
#include "QAction"
#include "processgraphics.h"
#include <iostream>
#include "pipeprovider.h"

PVisual::PVisual(){
    QVBoxLayout* thelayout=new QVBoxLayout();
    setLayout(thelayout);

    QToolBar* mainToolBar=new QToolBar("Main Toolbar");
    QAction* curAt=mainToolBar->addAction("StartAll");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(startButton()));
    curAt=mainToolBar->addAction("StopAll");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(stopButton()));
    curAt=mainToolBar->addAction("Clear");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(removeAllButton()));
    zoomInAction=mainToolBar->addAction("zoomIn");
    QObject::connect(zoomInAction,SIGNAL(triggered()),this,SLOT(zoomIn()));
    zoomOutAction=mainToolBar->addAction("zoomOut");
    QObject::connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(zoomOut()));

    thelayout->addWidget(mainToolBar);

    scene=new QGraphicsScene(this);
    scene->setItemIndexMethod(scene->NoIndex);
    view=new QGraphicsView(this);
    thelayout->addWidget(view);
    view->setScene(scene);
    view->setDragMode(view->ScrollHandDrag);


    sigcol=new TargetCollection();
    doubcol=new TargetCollection();
    boolcol=new TargetCollection();

    connect(scene,SIGNAL(selectionChanged()),SLOT(theSelectedHasChanged()));

}

PVisual::~PVisual(){
    removeAllButton();
    delete sigcol;
    delete doubcol;
    delete boolcol;
}

void PVisual::removeAllButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->removeMe();
    }
}

void PVisual::startButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->getProcessor()->start();
        i=i+1;
    }
}

void PVisual::stopButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->getProcessor()->stop();
        i=i+1;
    }
}

void PVisual::addPG(ProcessGraphics* newpg){
    if(newpg==0){
        std::cout<<"Numll pg given"<<std::endl;
        return ;
    }
    if(isExistPGName(newpg->getName()))return ;
    scene->addItem(newpg);
    foreach(PipeProvider* provider,newpg->getPipeProvider()){
        foreach(PipeFeed* feed,provider->getFeedlist()){
            scene->addItem(feed);
        }
    }

    pgraphics_list.append(newpg);
    newpg->setPos(view->mapToScene(view->width()/2-newpg->boundingRect().width()/2
                                   ,view->height()/2-newpg->boundingRect().height()/2));
}

void PVisual::removePG(ProcessGraphics *pg){
    scene->removeItem(pg);
    pgraphics_list.removeAll(pg);
    prevselectedlist.removeAll((ProcessGraphics*)pg);
    pg->setParent(0);
    delete pg;
}

bool PVisual::isExistPGName(QString name){
    int i=0;
    while(i<pgraphics_list.count()){
        if(pgraphics_list.at(i)->getName()==name)return true;
        i=i+1;
    }
    return false;
}

TargetCollection* PVisual::getSignalTargetCollection(){
    return sigcol;
}

TargetCollection* PVisual::getDoubleTargetCollection(){
    return doubcol;
}

TargetCollection* PVisual::getBoolTargetCollection(){
    return boolcol;
}

ProcessGraphics* PVisual::getProcessGraphics(QString name){
    int i=0;
    while(i<pgraphics_list.count()){
        if(pgraphics_list.at(i)->getName()==name)return pgraphics_list.at(i);
        i=i+1;
    }
    return 0;
}

void PVisual::zoomIn(){
    view->scale(1.2,1.2);
}

void PVisual::zoomOut(){
    view->scale(0.8,0.8);
}

void PVisual::theSelectedHasChanged(){
    foreach(QGraphicsItem* theitem,prevselectedlist){
        ProcessGraphics* pg=(ProcessGraphics*)theitem;
        pg->realign();
    }
    prevselectedlist=scene->selectedItems();
    foreach(QGraphicsItem* theitem,prevselectedlist){
        ProcessGraphics* pg=(ProcessGraphics*)theitem;
        pg->realign();
    }
}
