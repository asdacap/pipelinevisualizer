/*
    Copyright 2010-2011 Muhd Amirul Ashraf <asdacap@gmail.com>

    This file is part of PipelineVisualizer.

    PipelineVisualizer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation.

    PipelineVisualizer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PipelineVisualizer.  If not, see <http://www.gnu.org/licenses/>.

*/

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

class PipeProvider;
class PVisual;
class PipeProcessGraphicsProvider;

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
                    PipeProcessGraphicsProvider* prov,
                    QWidget* widget=0,
                    QRectF rect=QRectF());
    virtual void InitializeUi();
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QWidget* getWidget();

private:
    QGraphicsSimpleTextItem* text;
    QGraphicsProxyWidget* proxy;
    QRectF rect;
    QWidget* wid;
    QTimer reftimer;
    bool prevstatus;
    int thewidth;
    int theheight;
    QAction* removeAction;
    QAction* renameAction;
public slots:
    void timerElapsed();
    void removeMe();
    void renameMe();
};
#endif // WIDGETEDWidgetedProcessGraphics_H
