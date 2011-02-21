#ifndef PROCESSGRAPHICS_H
#define PROCESSGRAPHICS_H
#include <QGraphicsObject>
#include <QObject>
#include <QTimer>
#include "QAction"

class PipeProcessGraphicsProvider;
class PipeTarget;
class PipeProvider;
class SignalProcessor;

class ProcessGraphics:public QGraphicsObject
{
    Q_OBJECT
public:
    ProcessGraphics();
    virtual SignalProcessor* getProcessor()=0;
    virtual QString getName()=0;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void removeMe()=0;
    virtual PipeProcessGraphicsProvider* getProvider()=0;
    virtual QList<PipeTarget*> getTarget()=0;
    virtual QList<PipeProvider*> getPipeProvider()=0;
};

#endif // PROCESSGRAPHICS_H
