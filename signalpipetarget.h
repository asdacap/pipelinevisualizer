#ifndef SIGNALPIPETARGET_H
#define SIGNALPIPETARGET_H
#include "pipetarget.h"

class SignalPipeTarget:public PipeTarget
{
public:
    SignalPipeTarget(int id,SignalProcessor* process,TargetCollection* tg);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool ApplyFeed(PipeFeed *feed);
    void removeFeed(PipeFeed *feed);
};

#endif // SIGNALPIPETARGET_H
