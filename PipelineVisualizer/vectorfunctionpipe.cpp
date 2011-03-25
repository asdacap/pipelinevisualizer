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

#include "vectorfunctionpipe.h"
#include "widgetedprocessgraphics.h"

VectorFunctionPipe::VectorFunctionPipe(QVector<double> (*func)(QVector<double> ))
{
    thefunc=func;
    setOutputNum(1);
}

void VectorFunctionPipe::feedData(QVector<double> data, int counter, int channel){
    output_collection.at(0)->feedData(thefunc(data),counter);
}

VectorFunctionPipeProvider::VectorFunctionPipeProvider(
    QString name,
    QVector<double>  (*func)(QVector<double> ), PVisual *pv){
    thename=name;
    thefunc=func;
    PV=pv;
}

ProcessGraphics* VectorFunctionPipeProvider::newInstance(QString name){
    VectorFunctionPipe* mvfp=new VectorFunctionPipe(thefunc);
    return new WidgetedProcessGraphics(mvfp,name,1,1,0,0,0,0,PV,this);
}
