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

#include "doublepipefeed.h"
#include "doublepipeprovider.h"
#include <QPainter>
#include <QGraphicsScene>

DoublePipeProvider::DoublePipeProvider(ProcessGraphics *par, int id, TargetCollection *tg):
    PipeProvider(par,id,tg){

}

QRectF DoublePipeProvider::boundingRect() const{
    return QRectF(0,0,20,20);
}

PipeFeed* DoublePipeProvider::getNewFeed(){
    PipeFeed* pf=new DoublePipeFeed(this,target_collection);
    pf->setPos(scenePos());
    scene()->addItem(pf);
    feedlist.append(pf);
    return pf;
}

void DoublePipeProvider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::lightGray);
    painter->drawRect(boundingRect());
}
