#include "graphicproxywidgetgraphhack.h"
#include "iostream"
#include "QGraphicsSceneWheelEvent"

GraphicProxyWidgetGraphHack::GraphicProxyWidgetGraphHack()
{
}

void GraphicProxyWidgetGraphHack::mousePressEvent(QGraphicsSceneMouseEvent *event){

    grabMouse();
    QGraphicsProxyWidget::mousePressEvent(event);
}

void GraphicProxyWidgetGraphHack::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    QGraphicsProxyWidget::mouseReleaseEvent(event);
    ungrabMouse();
}

void GraphicProxyWidgetGraphHack::wheelEvent(QGraphicsSceneWheelEvent *event){
    QGraphicsProxyWidget::wheelEvent(event);
    event->accept();
}
