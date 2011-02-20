#ifndef WIDGETEDWidgetedProcessGraphics_H
#define WIDGETEDWidgetedProcessGraphics_H
#include <QWidget>
#include "processgraphics.h"
#include "QRect"
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


class WidgetedProcessGraphics:public ProcessGraphics
{
    Q_OBJECT
public:
    WidgetedProcessGraphics(SignalProcessor* theprocessor,
                    QString name,
                    int inputNum,
                    int outputNum,
                    int doubleinputNum,
                    int doubleOutputNum,
                    int boolInputNum,
                    int boolOutputNum,
                    PVisual* pvis);
    virtual void InitializeUi(int sInputNum,int sOutputNum,
                             int dInputNum, int dOutputNum,
                             int bInputNum, int bOutputNum);
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
#endif // WIDGETEDWidgetedProcessGraphics_H
