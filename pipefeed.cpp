#include "pipefeed.h"
#include <QGraphicsScene>
#include <iostream>

#include "pipeprovider.h"

PipeFeed::PipeFeed(PipeProvider* prov,TargetCollection* tg):QGraphicsEllipseItem()
{
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(ItemSendsGeometryChanges);
    QRect geom(0,0,20,20);
    setRect(geom);
    setBrush(QBrush(QColor(20,20,100,100)));
    setZValue(100);

    theline=new QGraphicsLineItem(this);
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

void PipeFeed::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(isset){
        curtarget->removeFeed(this);
        isset=false;
    }
}

void PipeFeed::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //CheckAligned();
    //std::cout<<"Intersect"<<std::endl;
    ungrabMouse();
    int i=0;
    QList<PipeTarget*> targ=target_collection->getTarget();
    while(i<targ.count()){
        if(collidesWithItem(targ.at(i))){
            PipeTarget* colled=targ.at(i);
            if(colled->ApplyFeed(this)){
            isset=true;
            curtarget=colled;
            return QGraphicsEllipseItem::mouseReleaseEvent(event);
            }else{
                std::cout<<"Target already contain feed"<<std::endl;
            }
        }
        i=i+1;
    }
    provider->FeedFail(this);
    scene()->removeItem(this);
    setParentItem(0);
    this->removeFromIndex();
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
