#ifndef FFTPLUGIN_H
#define FFTPLUGIN_H
#include "providerplugininterface.h"
#include <QtCore>
#include <QObject>

class FFtPlugin: public QObject, public ProviderPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(ProviderPluginInterface)
public:
    FFtPlugin();
    QList<PipeProcessGraphicsProvider*> getProviders(PVisual *pv);
};

#endif // FFTPLUGIN_H
