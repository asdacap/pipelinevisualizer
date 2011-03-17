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

#ifndef SIGNALBLOCKBUILDER_H
#define SIGNALBLOCKBUILDER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"
#include "widgetedprocessgraphics.h"
#include "QMap"

class SignalBlockBuilderProvider;

class SignalBlockBuilder:public SignalProcessor
{
    friend class SignalBlockBuilderProvider;
public:
    SignalBlockBuilder(int size,int resolution);
    void feedMe(QVector<double>,void* sender=0);
    void feedData(QVector<double> dat, int counter, int channel);
    int* getCounter();
protected:
    int blocksize;
    QVector<double>* inbuffer;
    int buffsize;
    int ct;
    int res;
};

class SignalBlockBuilderProvider:public PipeProcessGraphicsProvider{
public:
    SignalBlockBuilderProvider(PVisual* pv);
    PVisual* PV;
    QString getName();
    ProcessGraphics* newInstance();
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
};

#endif // SIGNALBLOCKBUILDER_H
