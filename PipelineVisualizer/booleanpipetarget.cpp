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

#include "booleanpipetarget.h"
#include "QPainter"
#include "pipefeed.h"
#include "pipeprovider.h"
#include "processgraphics.h"

BooleanPipeTarget::BooleanPipeTarget(int id, SignalProcessor *process, TargetCollection *tg):
    PipeTarget(id,process,tg){

}

void BooleanPipeTarget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::white));
    QPoint* poligo=new QPoint[3];
    poligo[0]=QPoint(boundingRect().width()/2,0);
    poligo[1]=QPoint(0,boundingRect().height());
    poligo[2]=QPoint(boundingRect().width(),boundingRect().height());
    painter->drawPolygon(poligo,3);
    delete [] poligo;
}

bool BooleanPipeTarget::ApplyFeed(PipeFeed *feed){
    if(!isAvail)return 0;
    isAvail=false;
    currentFeed=feed;
    currentFeed->provider->getProcessGraphics()->getProcessor()->setBoolOutput(currentFeed->provider->getId(),proc,cid);
    realign();
    return 1;
}

void BooleanPipeTarget::removeFeed(PipeFeed *feed){
    isAvail=true;
    currentFeed->provider->getProcessGraphics()->getProcessor()->unsetBoolOutput(currentFeed->provider->getId(),proc,cid);
}
