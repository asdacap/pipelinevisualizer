#include "doublepipetarget.h"
#include "QPainter"
#include "pipefeed.h"
#include "pipeprovider.h"

DoublePipeTarget::DoublePipeTarget(int id, SignalProcessor *process, TargetCollection *tg):
    PipeTarget(id,process,tg){

}

void DoublePipeTarget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(boundingRect());
}

bool DoublePipeTarget::ApplyFeed(PipeFeed *feed){
    if(!isAvail)return 0;
    isAvail=false;
    currentFeed=feed;
    currentFeed->provider->getProcessGraphics()->getProcessor()->setDoubleOutput(currentFeed->provider->getId(),proc,cid);
    realign();
    return 1;
}

void DoublePipeTarget::removeFeed(PipeFeed *feed){
    isAvail=true;
    currentFeed->provider->getProcessGraphics()->getProcessor()->unsetDoubleOutput(currentFeed->provider->getId(),proc,cid);
}
