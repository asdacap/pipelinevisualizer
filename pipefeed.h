#ifndef PIPEFEED_H
#define PIPEFEED_H
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include "targetcollection.h"
#include "pipeprovider.h"
#include "linearrow.h"

class PipeProvider;

class PipeFeed:public QGraphicsItem
{
public:
    PipeFeed(PipeProvider* prov,TargetCollection* tg);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ApplyTarget(PipeTarget* targ);
    void realign();
    void removeMe();
    QRectF boundingRect()const{return QRectF(0,0,20,20);}

    TargetCollection* target_collection;
    PipeTarget* curtarget;
    PipeProvider* provider;
private:
    void CheckAligned();
    LineArrow* theline;
    bool isset;
};

#endif // PIPEFEED_H
