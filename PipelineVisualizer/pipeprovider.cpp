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

#include "pipeprovider.h"
#include <iostream>
#include "pipefeed.h"
#include "QGraphicsScene"
#include "signalpipefeed.h"

PipeProvider::PipeProvider(ProcessGraphics* pg,int id,TargetCollection* tg):QGraphicsItem()
{
    pgraph=pg;
    target_collection=tg;
    cid=id;
    setAcceptHoverEvents(true);
    QGraphicsSimpleTextItem* sti=new QGraphicsSimpleTextItem(this);
    sti->setText(QVariant(id).toString());
    sti->setParentItem(this);
    sti->setPos(boundingRect().width()/2-sti->boundingRect().width()/2
                ,boundingRect().height()/2-sti->boundingRect().height()/2);


}

int PipeProvider::getId(){
    return cid;
}

ProcessGraphics* PipeProvider::getProcessGraphics(){
    return pgraph;
}

void PipeProvider::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    scene()->clearSelection();
    PipeFeed* pf=getNewFeed();
    pf->grabMouse();
    pf->setPos(scenePos());
}

void PipeProvider::realign(){
    int i=0;
    while(i<feedlist.count()){
        feedlist.at(i)->realign();
        i=i+1;
    }
}

QRectF PipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

void PipeProvider::FeedFail(PipeFeed *feed){
    feedlist.removeAll(feed);
}

void PipeProvider::mousePressEvent(QGraphicsSceneMouseEvent *event){
}

void PipeProvider::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    std::cout<<"mouse drag event"<<std::endl;
}

void PipeProvider::removeAllFeed(){
    while(0<feedlist.count()){
        feedlist.at(0)->removeMe();
        continue;
    }
}
