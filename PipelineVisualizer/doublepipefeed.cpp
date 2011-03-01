#include "doublepipefeed.h"
#include "QPainter"

DoublePipeFeed::DoublePipeFeed(PipeProvider *prov, TargetCollection *tc):PipeFeed(prov,tc){

}

QRectF DoublePipeFeed::boundingRect() const{
    return QRectF(0,0,20,20);
}

void DoublePipeFeed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(QColor(20,20,100,100)));
    painter->drawRect(boundingRect());
}
