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
#include "graphicproxywidgetgraphhack.h"

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
                    PVisual* pvis,
                    QWidget* widget,
                    QRectF rect);
    virtual void InitializeUi(int sInputNum,int sOutputNum,
                             int dInputNum, int dOutputNum,
                             int bInputNum, int bOutputNum,
                              QWidget* wid,QRectF rect);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    SignalProcessor* getProcessor();
    QString getName();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QList<PipeTarget*> targetlist;
    QList<PipeProvider*> providerlist;

private:

    QGraphicsProxyWidget* theproxwid;
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
