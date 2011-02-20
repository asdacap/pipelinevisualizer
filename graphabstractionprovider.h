#ifndef GRAPHABSTRACTIONPROVIDER_H
#define GRAPHABSTRACTIONPROVIDER_H
#include "graphabstraction.h"
#include "pipeproviderprovider.h"
#include "simplelinegraph.h"

class GraphAbstractionProvider:public PipeProcessGraphicsProvider{
public:
    GraphAbstractionProvider(PVisual* pvs);
    QString getName();
    ProcessGraphics* newInstance();
    PVisual* pv;
};


#endif // GRAPHABSTRACTIONPROVIDER_H
