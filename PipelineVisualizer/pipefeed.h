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

#ifndef PIPEFEED_H
#define PIPEFEED_H
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include "targetcollection.h"
#include "pipeprovider.h"
#include "linearrow.h"

class PipeProvider;

class PipeFeed:public QGraphicsItem
{
public:
    PipeFeed(PipeProvider* prov,TargetCollection* tg);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ApplyTarget(PipeTarget* targ);
    void realign();
    void removeMe();
    QRectF boundingRect()const{return QRectF(0,0,20,20);}
    void iupdate(){
        update();
        theline->update();
    }

    TargetCollection* target_collection;
    PipeTarget* curtarget;
    PipeProvider* provider;
private:
    void CheckAligned();
    LineArrow* theline;
    bool isset;
};

#endif // PIPEFEED_H
