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

#ifndef CONDITIONALOUTPUTSIGNALPIPE_H
#define CONDITIONALOUTPUTSIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "pvisual.h"

class ConditionalOutputSignalPipe:public SignalProcessor
{
public:
    ConditionalOutputSignalPipe();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class ConditionalOutputSignalPipeProvider:public PipeProcessGraphicsProvider{
public:
    ConditionalOutputSignalPipeProvider(PVisual* pv);
    PVisual* PV;
    QString getName();
    ProcessGraphics* newInstance(QString text);
};

#endif // CONDITIONALOUTPUTSIGNALPIPE_H
