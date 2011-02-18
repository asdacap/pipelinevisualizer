#ifndef BOOLEANPIPETARGET_H
#define BOOLEANPIPETARGET_H
#include "pipefeed.h"
#include "targetcollection.h"


class BooleanPipeTarget:public PipeTarget
{
public:
    BooleanPipeTarget(int id,SignalProcessor* process,TargetCollection* tg);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool ApplyFeed(PipeFeed *feed);
    void removeFeed(PipeFeed *feed);
};

#endif // BOOLEANPIPETARGET_H
