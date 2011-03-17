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

#ifndef PIPETARGET_H
#define PIPETARGET_H
#include <QGraphicsEllipseItem>
#include <QList>
#include "signalprocessor.h"
#include "targetcollection.h"

typedef struct TargetCollection TargetCollection;
typedef struct PipeFeed PipeFeed;

class PipeTarget:public QGraphicsItem
{
public:
    PipeTarget(int id,SignalProcessor* process,TargetCollection* tg);
    ~PipeTarget();
    virtual bool ApplyFeed(PipeFeed* feed)=0;
    void realign();
    virtual void removeFeed(PipeFeed* feed)=0;
    bool isAvailable();
    PipeFeed* getFeed();
    int getID();
    QRectF boundingRect() const;
    void removeFeed();
protected:
    TargetCollection* tc;
    PipeFeed* currentFeed;
    bool isAvail;
    SignalProcessor* proc;
    int cid;
};

#endif // PIPETARGET_H
