#include "pipetarget.h"
#include "pipefeed.h"
#include "QBrush"
#include "pipeprovider.h"
#include "signalprocessor.h"

PipeTarget::PipeTarget(int id,SignalProcessor* process,TargetCollection* target_collection)
{
    QRect geom(0,0,20,20);
    setRect(geom);
    setBrush(QBrush(Qt::white));

    cid=id;
    proc=process;

    QGraphicsSimpleTextItem* sti=new QGraphicsSimpleTextItem(this);
    sti->setText(QVariant(id).toString());
    sti->setParentItem(this);

    sti->setPos(boundingRect().width()/2-sti->boundingRect().width()/2
                ,boundingRect().height()/2-sti->boundingRect().height()/2);

    target_collection->addTarget(this);

    isAvail=true;
}

bool PipeTarget::ApplyFeed(PipeFeed *feed){
    if(!isAvail)return 0;
    isAvail=false;
    currentFeed=feed;
    currentFeed->provider->getProcessGraphics()->getProcessor()->setOutput(currentFeed->provider->getId(),proc,cid);
    realign();
    return 1;
}

void PipeTarget::realign(){
    if(isAvail)return;
        PipeFeed* feed=currentFeed;
        feed->setPos(feed->mapToParent(feed->mapFromScene(mapToScene(0,0))));

}

void PipeTarget::removeFeed(PipeFeed *feed){
    isAvail=true;
    currentFeed->provider->getProcessGraphics()->getProcessor()->unsetOutput(currentFeed->provider->getId(),proc,cid);
}
