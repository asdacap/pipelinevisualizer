#include "targetcollection.h"

TargetCollection::TargetCollection()
{
}

QList<PipeTarget*> TargetCollection::getTarget(){
    return targetcol;
}

void TargetCollection::addTarget(PipeTarget *t){
    targetcol.append(t);
}

void TargetCollection::removeTarget(PipeTarget *t){
    targetcol.removeAll(t);
}
