#ifndef BOOLEANPIPEPROVIDER_H
#define BOOLEANPIPEPROVIDER_H
#include "pipeprovider.h"

class BooleanPipeProvider:public PipeProvider
{
public:
    BooleanPipeProvider(ProcessGraphics* par,int id,TargetCollection* tg);
    PipeFeed* getNewFeed();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BOOLEANPIPEPROVIDER_H
