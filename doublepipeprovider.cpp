#include "doublepipefeed.h"
#include "doublepipeprovider.h"
#include <QPainter>
#include <QGraphicsScene>

DoublePipeProvider::DoublePipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF DoublePipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* DoublePipeProvider::getNewFeed(){
    PipeFeed* pf=new DoublePipeFeed(this,target_collection);
    pf->setPos(scenePos());
    scene()->addItem(pf);
    feedlist.append(pf);
    return pf;
}

void DoublePipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    painter->drawRect(boundingRect());
}
