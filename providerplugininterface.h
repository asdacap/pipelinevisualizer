#ifndef PROVIDERPLUGININTERFACE_H
#define PROVIDERPLUGININTERFACE_H
#include "pipeproviderprovider.h"
#include "QList"
#include "QObject"

class ProviderPluginInterface{
    virtual QList<PipeProcessGraphicsProvider*> getProviders();
};

Q_DECLARE_INTERFACE(ProviderPluginInterface,"ProviderPluginInterface/1.0")

#endif // PROVIDERPLUGININTERFACE_H
