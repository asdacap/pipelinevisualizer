#include "pipetarget.h"
#include "pipefeed.h"
#include "QBrush"
#include "pipeprovider.h"
#include "signalprocessor.h"

PipeTarget::PipeTarget(int id,SignalProcessor* process,TargetCollection* target_collection)
{

    cid=id;
    proc=process;

    QGraphicsSimpleTextItem* sti=new QGraphicsSimpleTextItem(this);
    sti->setText(QVariant(id).toString());
    sti->setParentItem(this);

    sti->setPos(boundingRect().width()/2-sti->boundingRect().width()/2
                ,boundingRect().height()/2-sti->boundingRect().height()/2);

    target_collection->addTarget(this);
    tc=target_collection;

    isAvail=true;
}

PipeTarget::~PipeTarget(){
    tc->removeTarget(this);
}

bool PipeTarget::isAvailable(){
    return isAvail;
}

PipeFeed* PipeTarget::getFeed(){
    return currentFeed;
}

int PipeTarget::getID(){
    return cid;
}

void PipeTarget::removeFeed(){
    if(isAvail)return;
    currentFeed->removeMe();
}



void PipeTarget::realign(){
    if(isAvail)return;
        PipeFeed* feed=currentFeed;
        feed->setPos(feed->mapToParent(feed->mapFromScene(mapToScene(0,0))));

}

QRectF PipeTarget::boundingRect() const{
    return QRectF(0,0,20,20);
}
