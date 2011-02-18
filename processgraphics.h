#ifndef PROCESSGRAPHICS_H
#define PROCESSGRAPHICS_H
#include <QGraphicsRectItem>
#include "targetcollection.h"
#include "pipetarget.h"
#include "pipeprovider.h"
#include "signalprocessor.h"

typedef struct PipeProvider PipeProvider;

class ProcessGraphics:public QGraphicsRectItem
{
public:
    ProcessGraphics(SignalProcessor* theprocessor,QString name,int inputNum,int outputNum);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    SignalProcessor* getProcessor();
    QString getName();

private:
    QList<PipeTarget*> targetlist;
    QList<PipeProvider*> providerlist;
    SignalProcessor* processor;
    QString thename;
    int in;
    int on;
};

#endif // PROCESSGRAPHICS_H
