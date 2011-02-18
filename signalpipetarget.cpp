#include "signalpipetarget.h"
#include "QPainter"
#include "pipefeed.h"
#include "pipeprovider.h"

SignalPipeTarget::SignalPipeTarget(int id, SignalProcessor *process, TargetCollection *tg):
    PipeTarget(id,process,tg){

}

void SignalPipeTarget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::white));
    painter->drawEllipse(boundingRect());
}

bool SignalPipeTarget::ApplyFeed(PipeFeed *feed){
    if(!isAvail)return 0;
    isAvail=false;
    currentFeed=feed;
    currentFeed->provider->getProcessGraphics()->getProcessor()->setOutput(currentFeed->provider->getId(),proc,cid);
    realign();
    return 1;
}

void SignalPipeTarget::removeFeed(PipeFeed *feed){
    isAvail=true;
    currentFeed->provider->getProcessGraphics()->getProcessor()->unsetOutput(currentFeed->provider->getId(),proc,cid);
}
