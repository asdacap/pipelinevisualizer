#ifndef PROCESSGRAPHICS_H
#define PROCESSGRAPHICS_H
#include <QGraphicsObject>
#include <QObject>
#include "targetcollection.h"
#include "pipetarget.h"
#include "pipeprovider.h"
#include "signalprocessor.h"
#include "pvisual.h"
#include <QTimer>
#include "QAction"

typedef struct PipeProvider PipeProvider;
typedef struct PVisual PVisual;

class ProcessGraphics:public QGraphicsObject
{
    Q_OBJECT
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
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    QList<PipeTarget*> targetlist;
    QList<PipeProvider*> providerlist;

    SignalProcessor* processor;
    QString thename;
    QTimer reftimer;
    int in;
    int on;
    bool prevstatus;
    int thewidth;
    int theheight;
    QAction* removeAction;
    PVisual* pv;
public slots:
    void timerElapsed();
    void removeMe();
};

#endif // PROCESSGRAPHICS_H
