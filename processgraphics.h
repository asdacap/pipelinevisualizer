#ifndef PROCESSGRAPHICS_H
#define PROCESSGRAPHICS_H
#include <QGraphicsRectItem>
#include "targetcollection.h"
#include "pipetarget.h"
#include "pipeprovider.h"
#include "signalprocessor.h"
#include "pvisual.h"

typedef struct PipeProvider PipeProvider;
typedef struct PVisual PVisual;

class ProcessGraphics:public QGraphicsRectItem
{
public:
    ProcessGraphics(SignalProcessor* theprocessor,
                    QString name,
                    int inputNum,
                    int outputNum,
                    int doubleinputNum,
                    int doubleOutputNum,
                    int boolInputNum,
                    int boolOutputNum,
                    PVisual* pvis);
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
