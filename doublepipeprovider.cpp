#include "doublepipefeed.h"
#include "doublepipeprovider.h"

DoublePipeProvider::DoublePipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF DoublePipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* DoublePipeProvider::getNewFeed(){
    return new DoublePipeFeed(this,target_collection);
}

void DoublePipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    painter->drawRect(boundingRect());
}
