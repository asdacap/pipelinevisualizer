#ifndef SIGNALPIPEFEED_H
#define SIGNALPIPEFEED_H
#include "pipefeed.h"
#include "targetcollection.h"

class SignalPipeFeed:public PipeFeed
{
public:
    SignalPipeFeed(PipeProvider* prov,TargetCollection* tc);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SIGNALPIPEFEED_H
