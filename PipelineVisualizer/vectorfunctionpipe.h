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

#ifndef VECTORFUNCTIONPIPE_H
#define VECTORFUNCTIONPIPE_H
#include <QVector>
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class VectorFunctionPipe: public SignalProcessor
{
public:
    VectorFunctionPipe(QVector<double> (*func)(QVector<double>  dat));
    void feedData(QVector<double> data,int counter,int channel);

private:
    QVector<double>  (*thefunc)(QVector<double> dat);
};

class VectorFunctionPipeProvider:public PipeProcessGraphicsProvider{
public:
    VectorFunctionPipeProvider(QString name,QVector<double> (*func)(QVector<double>  dat),PVisual* pv);
    PVisual* PV;
    QString thename;
    QVector<double>  (*thefunc)(QVector<double>  dat);
    QString getName(){return thename;}
    ProcessGraphics* newInstance(QString name);
};

#endif // VECTORFUNCTIONPIPE_H
