#ifndef PIPETARGET_H
#define PIPETARGET_H
#include <QGraphicsEllipseItem>
#include <QList>
#include "signalprocessor.h"

typedef struct PipeFeed PipeFeed;

class PipeTarget:public QGraphicsEllipseItem
{
public:
    PipeTarget(int id,SignalProcessor* process);
    bool ApplyFeed(PipeFeed* feed);
    void realign();
    void removeFeed(PipeFeed* feed);
private:
    PipeFeed* currentFeed;
    bool isAvail;
    SignalProcessor* proc;
    int cid;
};

#endif // PIPETARGET_H
