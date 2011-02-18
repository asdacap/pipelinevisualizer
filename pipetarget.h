#ifndef PIPETARGET_H
#define PIPETARGET_H
#include <QGraphicsEllipseItem>
#include <QList>
#include "signalprocessor.h"
#include "targetcollection.h"

typedef struct TargetCollection TargetCollection;
typedef struct PipeFeed PipeFeed;

class PipeTarget:public QGraphicsItem
{
public:
    PipeTarget(int id,SignalProcessor* process,TargetCollection* tg);
    virtual bool ApplyFeed(PipeFeed* feed)=0;
    void realign();
    virtual void removeFeed(PipeFeed* feed)=0;
    QRectF boundingRect() const;
protected:
    PipeFeed* currentFeed;
    bool isAvail;
    SignalProcessor* proc;
    int cid;
};

#endif // PIPETARGET_H
