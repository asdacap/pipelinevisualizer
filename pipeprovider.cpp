#include "pipeprovider.h"
#include <iostream>
#include "pipefeed.h"
#include "QGraphicsScene"

PipeProvider::PipeProvider(ProcessGraphics* pg,int id,TargetCollection* tg):QGraphicsEllipseItem()
{
    pgraph=pg;
    target_collection=tg;
    cid=id;
    setRect(0,0,20,20);
    setBrush(Qt::lightGray);
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
    PipeFeed* pf=new PipeFeed(this,target_collection);

    pf->setPos(scenePos());


    scene()->addItem(pf);
    feedlist.append(pf);

    ungrabMouse();

    pf->grabMouse();
}

void PipeProvider::realign(){
    int i=0;
    while(i<feedlist.count()){
        feedlist.at(i)->realign();
        i=i+1;
    }
}

void PipeProvider::FeedFail(PipeFeed *feed){
    feedlist.removeAll(feed);
}

void PipeProvider::mousePressEvent(QGraphicsSceneMouseEvent *event){
}

void PipeProvider::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    std::cout<<"mouse drag event"<<std::endl;
}
