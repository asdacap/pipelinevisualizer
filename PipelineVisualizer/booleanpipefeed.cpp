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

#include "booleanpipefeed.h"
#include <QPainter>

BooleanPipeFeed::BooleanPipeFeed(PipeProvider *prov, TargetCollection *tc):PipeFeed(prov,tc){

}

QRectF BooleanPipeFeed::boundingRect() const{
    return QRectF(0,0,20,20);
}

void BooleanPipeFeed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(QColor(20,20,100,100)));
    QPoint* poligo=new QPoint[3];
    poligo[0]=QPoint(boundingRect().width()/2,0);
    poligo[1]=QPoint(0,boundingRect().height());
    poligo[2]=QPoint(boundingRect().width(),boundingRect().height());
    painter->drawPolygon(poligo,3);
    delete [] poligo;
}
