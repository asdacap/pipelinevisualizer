#include "signalpipeprovider.h"
#include "signalpipefeed.h"
#include <QPainter>

SignalPipeProvider::SignalPipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF SignalPipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* SignalPipeProvider::getNewFeed(){
    return new SignalPipeFeed(this,target_collection);
}

void SignalPipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    painter->drawEllipse(boundingRect());
}
