#ifndef PIPEPROVIDERPROVIDER_H
#define PIPEPROVIDERPROVIDER_H
#include <QString>
#include <QMap>

class ProcessGraphics;
class PVisual;

class PipeProcessGraphicsProvider
{
public:
    PipeProcessGraphicsProvider();
    virtual QString getName();
    virtual ProcessGraphics* newInstance();
    virtual ProcessGraphics* newInstance(QString name);
    virtual QMap<QString,QString> getSettings(ProcessGraphics* pg);
    virtual ProcessGraphics* newInstance(QMap<QString,QString> setting);
    virtual QString getToolTip();
    virtual QString getProviderToolTip(int id);
    virtual QString getTargetToolTip(int id);
    QString nameCandidate();
private:
    int counter;
};

#endif // PIPEPROVIDERPROVIDER_H
