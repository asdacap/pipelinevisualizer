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


#include "pipefeed.h"
#include <QGraphicsScene>
#include <iostream>


PipeFeed::PipeFeed(PipeProvider* prov,TargetCollection* tg):QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(ItemSendsGeometryChanges);
    setZValue(100);

    theline=new LineArrow();
    theline->setParentItem(this);
    theline->setPos(boundingRect().width()/2,boundingRect().height()/2);
    theline->setZValue(-1);
    theline->setFlags(QGraphicsItem::ItemStacksBehindParent);

    isset=false;

    provider=prov;
    target_collection=tg;

}

QVariant PipeFeed::itemChange(GraphicsItemChange change, const QVariant &value){
    switch (change) {
     case ItemPositionHasChanged:{
        realign();

         break;}
     default:
         break;
     };

     return QGraphicsItem::itemChange(change, value);
}

void PipeFeed::mousePressEvent(QGraphicsSceneMouseEvent*){
    if(isset){
        curtarget->removeFeed(this);
        isset=false;
    }
}

void PipeFeed::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    int i=0;
    QGraphicsItem::mouseReleaseEvent(event);
    ungrabMouse();
    QList<PipeTarget*> targ=target_collection->getTarget();
    while(i<targ.count()){
        if(collidesWithItem(targ.at(i))){
            PipeTarget* colled=targ.at(i);
            ApplyTarget(colled);
            return ;
        }
        i=i+1;
    }
    removeMe();
}

void PipeFeed::ApplyTarget(PipeTarget *colled){
    if(colled->ApplyFeed(this)){
    isset=true;
    curtarget=colled;
    }else{
        removeMe();
        std::cout<<"Target already contain feed"<<std::endl;
    }
}

void PipeFeed::removeMe(){
    if(isset){
        curtarget->removeFeed(this);
        isset=false;
    }
    provider->FeedFail(this);
    scene()->removeItem(this);
    setParentItem(0);
    //this->removeFromIndex();
    delete this;
}

void PipeFeed::realign(){
    if(isset){
        curtarget->realign();

    }
    QPointF transpose=mapFromScene(provider->scenePos());
    theline->setLine(
                    boundingRect().width()/2,
                    boundingRect().height()/2,
                    transpose.x()+provider->boundingRect().width()/2,
                    transpose.y()+provider->boundingRect().height()/2
                    );

}
