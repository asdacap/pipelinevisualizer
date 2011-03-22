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

#ifndef LINEARROW_H
#define LINEARROW_H
#include "QGraphicsItem"

class LineArrow:public QGraphicsItem
{
public:
    LineArrow(QGraphicsItem* firstItem,QGraphicsItem* secondItem);
    double width;
    double height;
    int x1i;
    int y1i;
    int x2i;
    int y2i;
    bool diagonaldown;
    QGraphicsItem* firstItem;
    QGraphicsItem* secondItem;
    void setLine(int x1,int y1,int x2,int y2);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINEARROW_H
