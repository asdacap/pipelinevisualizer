#include "signalpipeprovider.h"
#include "signalpipefeed.h"
#include <QPainter>
#include <QGraphicsScene>

SignalPipeProvider::SignalPipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF SignalPipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* SignalPipeProvider::getNewFeed(){
    PipeFeed* pf=new SignalPipeFeed(this,target_collection);
    pf->setPos(scenePos());
    scene()->addItem(pf);
    feedlist.append(pf);
    return pf;
}

void SignalPipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    painter->drawEllipse(boundingRect());
}
