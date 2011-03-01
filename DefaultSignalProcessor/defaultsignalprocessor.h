#ifndef DEFAULTSIGNALPROCESSOR_H
#define DEFAULTSIGNALPROCESSOR_H
#include "providerplugininterface.h"
#include <QtCore>
#include <QObject>

class DefaultSignalProcessor:public QObject,public ProviderPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(ProviderPluginInterface)
public:
    DefaultSignalProcessor();
    QList<PipeProcessGraphicsProvider*> getProviders(PVisual *pv);
};

#endif // DEFAULTSIGNALPROCESSOR_H
