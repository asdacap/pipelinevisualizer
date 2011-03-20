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

#ifndef MULTIVECTORFUNCTIONPIPE_H
#define MULTIVECTORFUNCTIONPIPE_H
#include <QVector>
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class MultiVectorFunctionPipe: public SignalProcessor
{
public:
    MultiVectorFunctionPipe(int il,int ol,QVector<QVector<double> > (*func)(QVector<QVector<double> > dat));
    void feedMe(QVector<double>, void *sender);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);

private:
    QVector<QVector<double> > (*thefunc)(QVector<QVector<double> > dat);
};

class MultiVectorFunctionPipeProvider:public PipeProcessGraphicsProvider{
public:
    MultiVectorFunctionPipeProvider(QString name,int in,int on,QVector<QVector<double> > (*func)(QVector<QVector<double> > dat),PVisual* pv);
    PVisual* PV;
    QString thename;
    int inputNum;
    int outputNum;
    QVector<QVector<double> > (*thefunc)(QVector<QVector<double> > dat);
    QString getName(){return thename;}
    ProcessGraphics* newInstance(QString name);
};

#endif // MULTIVECTORFUNCTIONPIPE_H
