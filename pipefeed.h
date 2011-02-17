#ifndef PIPEFEED_H
#define PIPEFEED_H
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include "targetcollection.h"
#include "StaticData.h"

typedef struct PipeProvider PipeProvider;

class PipeFeed:public QGraphicsEllipseItem
{
public:
    PipeFeed(PipeProvider* prov);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void realign();

    PipeTarget* curtarget;
    PipeProvider* provider;
private:
    void CheckAligned();
    QGraphicsLineItem* theline;
    bool isset;
};

#endif // PIPEFEED_H
