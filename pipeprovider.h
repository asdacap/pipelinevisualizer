#ifndef PIPEPROVIDER_H
#define PIPEPROVIDER_H
#include <QGraphicsItem>
#include "processgraphics.h"
#include "pipefeed.h"
#include "pipetarget.h"
#include "targetcollection.h"

typedef struct ProcessGraphics ProcessGraphics;

class PipeProvider:public QGraphicsItem
{
public:
    PipeProvider(ProcessGraphics* par,int id,TargetCollection* tg);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void FeedFail(PipeFeed* feed);
    void realign();
    virtual PipeFeed* getNewFeed()=0;
    QRectF boundingRect() const;
    void registerTarget(PipeTarget* target);
    void unregisterTarget(PipeTarget* target);
    int getId();
    ProcessGraphics* getProcessGraphics();

protected:
    int cid;
    TargetCollection* target_collection;
    ProcessGraphics* pgraph;
    QList<PipeTarget*> inputlist;
    QList<PipeFeed*> feedlist;
};

#endif // PIPEPROVIDER_H
