#ifndef BOOLEANGENERATORPROVIDER_H
#define BOOLEANGENERATORPROVIDER_H
#include "booleangenerator.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"

class BooleanGeneratorProvider:public PipeProcessGraphicsProvider
{
public:
    BooleanGeneratorProvider(PVisual* pv);
    QString getName();
    ProcessGraphics* newInstance();

    PVisual* PV;
};

#endif // BOOLEANGENERATORPROVIDER_H
