#ifndef DOUBLEPIPEFEED_H
#define DOUBLEPIPEFEED_H
#include "pipefeed.h"

class DoublePipeFeed:public PipeFeed
{public:
    DoublePipeFeed(PipeProvider* prov,TargetCollection* tc);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DOUBLEPIPEFEED_H
