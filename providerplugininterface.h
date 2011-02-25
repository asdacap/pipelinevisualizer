#ifndef PROVIDERPLUGININTERFACE_H
#define PROVIDERPLUGININTERFACE_H
#include "pipeproviderprovider.h"
#include "QList"
#include "QObject"
class PVisual;

class ProviderPluginInterface{
public:
    virtual QList<PipeProcessGraphicsProvider*> getProviders(PVisual* pv)=0;
};

Q_DECLARE_INTERFACE(ProviderPluginInterface,"ProviderPluginInterface/1.0")

#endif // PROVIDERPLUGININTERFACE_H
