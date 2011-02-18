#ifndef BOOLEANPIPEFEED_H
#define BOOLEANPIPEFEED_H
#include "pipefeed.h"
#include "targetcollection.h"

class BooleanPipeFeed:public PipeFeed
{
public:
    BooleanPipeFeed(PipeProvider* prov,TargetCollection* tc);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOOLEANPIPEFEED_H
