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

#ifndef PINKNOISEREMOVER_H
#define PINKNOISEREMOVER_H
#include "signalprocessor.h"
#include "widgetedprocessgraphics.h"
#include "pipeproviderprovider.h"

class PinkNoiseRemover:public SignalProcessor
{
public:
    PinkNoiseRemover();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class PinkNoiseRemoverProvider:public PipeProcessGraphicsProvider{
public:
    PinkNoiseRemoverProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "PinkNoiseRemover";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new PinkNoiseRemover(),name,1,1,1,0,0,0,PV,this);
    }
};

#endif // PINKNOISEREMOVER_H
