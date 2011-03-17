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

#ifndef PIPEPROVIDER_H
#define PIPEPROVIDER_H
#include <QGraphicsItem>
#include "pipefeed.h"
#include "pipetarget.h"
#include "targetcollection.h"

class ProcessGraphics;

class PipeProvider:public QGraphicsItem
{
public:
    PipeProvider(ProcessGraphics* par,int id,TargetCollection* tg);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void FeedFail(PipeFeed* feed);
    void realign();
    virtual PipeFeed* getNewFeed()=0;
    QRectF boundingRect() const;
    void registerTarget(PipeTarget* target);
    void unregisterTarget(PipeTarget* target);
    int getId();
    ProcessGraphics* getProcessGraphics();
    void removeAllFeed();

protected:
    int cid;
    TargetCollection* target_collection;
    ProcessGraphics* pgraph;
    QList<PipeTarget*> inputlist;
    QList<PipeFeed*> feedlist;
};

#endif // PIPEPROVIDER_H
