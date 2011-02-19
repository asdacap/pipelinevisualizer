#ifndef SIGNALPIPEPROVIDER_H
#define SIGNALPIPEPROVIDER_H
#include "pipeprovider.h"

class SignalPipeProvider:public PipeProvider
{
public:
    SignalPipeProvider(ProcessGraphics* par,int id,TargetCollection* tg);
    PipeFeed* getNewFeed();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // SIGNALPIPEPROVIDER_H
