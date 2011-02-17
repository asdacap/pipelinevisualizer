#ifndef PIPEPROVIDER_H
#define PIPEPROVIDER_H
#include <QGraphicsItem>
#include "processgraphics.h"
#include "pipefeed.h"
#include "pipetarget.h"

typedef struct ProcessGraphics ProcessGraphics;

class PipeProvider:public QGraphicsEllipseItem
{
public:
    PipeProvider(ProcessGraphics* par,int id);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void FeedFail(PipeFeed* feed);
    void realign();

    void registerTarget(PipeTarget* target);
    void unregisterTarget(PipeTarget* target);
    int getId();
    ProcessGraphics* getProcessGraphics();

private:
    int cid;
    ProcessGraphics* pgraph;
    QList<PipeTarget*> inputlist;
    QList<PipeFeed*> feedlist;
};

#endif // PIPEPROVIDER_H
