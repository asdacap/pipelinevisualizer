#ifndef PVISUAL_H
#define PVISUAL_H
#include "targetcollection.h"
#include "pipeproviderprovider.h"

class PVisual{
public:
    virtual void removePG(ProcessGraphics* )=0;
    virtual bool isExistPGName(QString name)=0;
    virtual TargetCollection* getSignalTargetCollection()=0;
    virtual TargetCollection* getDoubleTargetCollection()=0;
    virtual TargetCollection* getBoolTargetCollection()=0;
};

#endif // PVISUAL_H
