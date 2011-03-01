#include "defaultsignalprocessor.h"
#include "simpleprocessgraphicsprovidertemplate.h"
#include "doublemultiply.h"

DefaultSignalProcessor::DefaultSignalProcessor()
{
}

QList<PipeProcessGraphicsProvider*> DefaultSignalProcessor::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> thelist;
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiplyExternal",pv,0,0,2,1,0,0));
    return thelist;
}

Q_EXPORT_PLUGIN2(DefaultSignalProcessor,DefaultSignalProcessor)
