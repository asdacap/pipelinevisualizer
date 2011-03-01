#ifndef DOUBLEPIPEPROVIDER_H
#define DOUBLEPIPEPROVIDER_H
#include "pipeprovider.h"

class DoublePipeProvider:public PipeProvider
{
public:
    DoublePipeProvider(ProcessGraphics* par,int id,TargetCollection* tg);
    PipeFeed* getNewFeed();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // DOUBLEPIPEPROVIDER_H
