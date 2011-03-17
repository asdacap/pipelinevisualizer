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

#ifndef SELECTIVESIGNALELIMINATION_H
#define SELECTIVESIGNALELIMINATION_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class SelectiveSignalElimination:public SignalProcessor
{
public:
    SelectiveSignalElimination();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class SelectiveSignalEliminationProvider:public PipeProcessGraphicsProvider{
public:
    SelectiveSignalEliminationProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "SelectiveSignalElimination";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new SelectiveSignalElimination(),name,2,2,0,0,0,0,PV,this);
    }
};


#endif // SELECTIVESIGNALELIMINATION_H
