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



class ProcessGraphics:public QGraphicsObject
{
    Q_OBJECT
public:
    ProcessGraphics();
    virtual SignalProcessor* getProcessor()=0;
    virtual QString getName()=0;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void removeMe();
};

#endif // PROCESSGRAPHICS_H
