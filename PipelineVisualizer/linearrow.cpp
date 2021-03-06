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

#include "linearrow.h"
#include "QPainter"
#include "cmath"
#include <iostream>
#define PI 3.142857143


LineArrow::LineArrow(QGraphicsItem* fItem,QGraphicsItem* secItem)
{
    firstItem=fItem;
    secondItem=secItem;
    width=0;
    height=0;
    x1i=0;
    x2i=0;
    y1i=0;
    y2i=0;
}

void LineArrow::setLine(int x1, int y1, int x2, int y2){
    int nx=x1;
    if(x2<x1){
        nx=x2;
    }
    int ny=y1;
    if(y2<y1)ny=y2;
    setPos(nx,ny);
    width=x1-x2;
    if(width<0)width=width*-1;
    height=y1-y2;
    if(height<0)height=height*-1;

    x1i=x1-nx;
    x2i=x2-nx;
    y1i=y1-ny;
    y2i=y2-ny;

    update();


}

void inline DrawArrow(QPainter* painter){
    painter->drawLine(0,0,5,-9);
    painter->drawLine(0,0,-5,-9);
}

QPoint inline findMiddleCoordinate(double ratio,int x1,int y1,int x2,int y2){
    int nx=x1+(x2-x1)*ratio;
    int ny=y1+(y2-y1)*ratio;
    return QPoint(nx,ny);
}

void LineArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(firstItem->isSelected()|secondItem->isSelected()){
        painter->setPen(QColor(0,0,0,250));
    }else{
        painter->setPen(QColor(0,0,0,50));
    }
    painter->drawLine(x1i,y1i,x2i,y2i);


    double angle;

    if(y2i-y1i==0){
        angle=90;
    }else{
        angle=std::atan2(double(y2i-y1i),double(x2i-x1i));
        angle=angle/PI*180;
        angle=angle+90;
    }

    QTransform tr=painter->transform();
    QPoint tp=findMiddleCoordinate(0.5,x1i,y1i,x2i,y2i);
    painter->translate(tp.x(),tp.y());
    painter->rotate(angle);
    DrawArrow(painter);

    painter->setTransform(tr);
    tp=findMiddleCoordinate(0.25,x1i,y1i,x2i,y2i);
    painter->translate(tp.x(),tp.y());
    painter->rotate(angle);
    DrawArrow(painter);

    painter->setTransform(tr);
    tp=findMiddleCoordinate(0.75,x1i,y1i,x2i,y2i);
    painter->translate(tp.x(),tp.y());
    painter->rotate(angle);
    DrawArrow(painter);

}

QRectF LineArrow::boundingRect() const{
    return QRectF(-10,-10,width+20,height+20);
}
