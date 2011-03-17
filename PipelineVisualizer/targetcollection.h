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

#ifndef GRAPHITEMCOLLECTION_H
#define GRAPHITEMCOLLECTION_H
#include "pipetarget.h"
#include <QList>

typedef struct PipeTarget PipeTarget;

class TargetCollection
{
public:
    TargetCollection();
    QList<PipeTarget*> getTarget();
    void addTarget(PipeTarget* t);
    void removeTarget(PipeTarget* t);

private:
    QList<PipeTarget*> targetcol;
};

#endif // GRAPHITEMCOLLECTION_H
