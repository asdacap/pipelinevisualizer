#include "booleanpipefeed.h"
#include <QPainter>

BooleanPipeFeed::BooleanPipeFeed(PipeProvider *prov, TargetCollection *tc):PipeFeed(prov,tc){

}

QRectF BooleanPipeFeed::boundingRect() const{
    return QRectF(0,0,20,20);
}

void BooleanPipeFeed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(QColor(20,20,100,100)));
    QPoint* poligo=new QPoint[3];
    poligo[0]=QPoint(boundingRect().width()/2,0);
    poligo[1]=QPoint(0,boundingRect().height());
    poligo[2]=QPoint(boundingRect().width(),boundingRect().height());
    painter->drawPolygon(poligo,3);
    delete [] poligo;
}
