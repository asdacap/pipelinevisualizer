#ifndef DOUBLEPIPETARGET_H
#define DOUBLEPIPETARGET_H
#include "pipetarget.h"

class DoublePipeTarget:public PipeTarget
{
public:
    DoublePipeTarget(int id,SignalProcessor* process,TargetCollection* tg);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool ApplyFeed(PipeFeed *feed);
    void removeFeed(PipeFeed *feed);
};

#endif // DOUBLEPIPETARGET_H
