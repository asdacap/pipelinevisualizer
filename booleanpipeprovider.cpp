#include "booleanpipeprovider.h"
#include "booleanpipefeed.h"

BooleanPipeProvider::BooleanPipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF BooleanPipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* BooleanPipeProvider::getNewFeed(){
    return new BooleanPipeFeed(this,target_collection);
}

void BooleanPipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    QPoint* poligo=new QPoint[3];
    poligo[0]=QPoint(boundingRect().width()/2,0);
    poligo[1]=QPoint(0,boundingRect().height());
    poligo[2]=QPoint(boundingRect().width(),boundingRect().height());
    painter->drawPolygon(poligo,3);
    delete [] poligo;
}
