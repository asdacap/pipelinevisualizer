#ifndef GRAPHITEMCOLLECTION_H
#define GRAPHITEMCOLLECTION_H
#include "pipetarget.h"
#include <QList>

typedef struct PipeTarget PipeTarget;

class TargetCollection
{
public:
    TargetCollection();
    QList<PipeTarget*> getTarget();
    void addTarget(PipeTarget* t);
    void removeTarget(PipeTarget* t);

private:
    QList<PipeTarget*> targetcol;
};

#endif // GRAPHITEMCOLLECTION_H
