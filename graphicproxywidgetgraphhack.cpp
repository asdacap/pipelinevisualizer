#include "graphicproxywidgetgraphhack.h"
#include "iostream"

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
