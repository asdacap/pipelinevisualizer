#ifndef DEFAULTPROCESSGRAPHICS_H
#define DEFAULTPROCESSGRAPHICS_H

#include <QWidget>
#include "processgraphics.h"
#include "QRect"
#include <QGraphicsObject>
#include <QObject>
#include "targetcollection.h"
#include "pvisual.h"
#include <QTimer>
#include "QAction"

class PipeProvider;
class PVisual;
class SignalProcessor;


class DefaultProcessGraphics:public ProcessGraphics
{
    Q_OBJECT
public:
    DefaultProcessGraphics(SignalProcessor* theprocessor,
                    QString name,
                    int inputNum,
                    int outputNum,
                    int doubleinputNum,
                    int doubleOutputNum,
                    int boolInputNum,
                    int boolOutputNum,
                    PVisual* pvis,
                    PipeProcessGraphicsProvider* prov);
    virtual void InitializeUi(int sInputNum,int sOutputNum,
                             int dInputNum, int dOutputNum,
                             int bInputNum, int bOutputNum);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    SignalProcessor* getProcessor();
    QString getName();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    PipeProcessGraphicsProvider* getProvider();
    QList<PipeTarget*> getTarget();
    QList<PipeProvider*> getPipeProvider();

private:
    QGraphicsSimpleTextItem* text;
    PipeProcessGraphicsProvider* provider;
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
    QAction* renameAction;
    PVisual* pv;
public slots:
    void timerElapsed();
    void removeMe();
};

#endif // DEFAULTPROCESSGRAPHICS_H
