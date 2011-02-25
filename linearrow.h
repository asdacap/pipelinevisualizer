#ifndef LINEARROW_H
#define LINEARROW_H
#include "QGraphicsItem"

class LineArrow:public QGraphicsItem
{
public:
    LineArrow();
    double width;
    double height;
    int x1i;
    int y1i;
    int x2i;
    int y2i;
    bool diagonaldown;
    void setLine(int x1,int y1,int x2,int y2);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINEARROW_H
