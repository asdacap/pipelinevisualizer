#ifndef GRAPHICPROXYWIDGETGRAPHHACK_H
#define GRAPHICPROXYWIDGETGRAPHHACK_H
#include <QGraphicsProxyWidget>

class GraphicProxyWidgetGraphHack:public QGraphicsProxyWidget
{
public:
    GraphicProxyWidgetGraphHack();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
};

#endif // GRAPHICPROXYWIDGETGRAPHHACK_H
