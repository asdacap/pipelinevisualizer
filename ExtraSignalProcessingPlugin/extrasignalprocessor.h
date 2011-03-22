#ifndef EXTRASIGNALPROCESSOR_H
#define EXTRASIGNALPROCESSOR_H
#include "providerplugininterface.h"
#include <QtCore>
#include <QObject>

class ExtraSignalProcessor:public QObject,public ProviderPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(ProviderPluginInterface)
public:
    ExtraSignalProcessor();
    QList<PipeProcessGraphicsProvider*> getProviders(PVisual *pv);
};



#endif // EXTRASIGNALPROCESSOR_H
