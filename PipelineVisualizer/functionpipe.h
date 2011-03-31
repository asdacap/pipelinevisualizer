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

#ifndef FUNCTIONPIPE_H
#define FUNCTIONPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class FunctionPipe: public SignalProcessor
{
public:
    FunctionPipe(double (*funct)(double));
    void feedData(QVector<double> dat, int counter, int channel);
private:
    double (*thefunction)(double);
};

class FunctionPipeProvider:public PipeProcessGraphicsProvider{
public:
    QString name;
    PVisual* PV;
    FunctionPipeProvider(QString thename,double (*funct)(double),PVisual* pv):PipeProcessGraphicsProvider(pv){
        name=thename;
        thefunct=funct;
        PV=pv;
    }

    double (*thefunct)(double);

    QString getName(){
        return name;
    }

    ProcessGraphics* newInstance(QString name){
        FunctionPipe* fp=new FunctionPipe(thefunct);
        return new WidgetedProcessGraphics(fp,name,1,1,0,0,0,0,PV,this);
    }

};

#endif // FUNCTIONPIPE_H
