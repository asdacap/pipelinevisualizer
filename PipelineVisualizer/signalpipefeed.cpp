#include "signalpipefeed.h"
#include <QPainter>

SignalPipeFeed::SignalPipeFeed(PipeProvider *prov, TargetCollection *tc):PipeFeed(prov,tc){

}

QRectF SignalPipeFeed::boundingRect() const{
    return QRectF(0,0,20,20);
}

void SignalPipeFeed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(QColor(20,20,100,100)));
    painter->drawEllipse(boundingRect());
}
