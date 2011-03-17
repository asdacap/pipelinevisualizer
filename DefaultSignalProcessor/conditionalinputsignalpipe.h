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

#ifndef CONDITIONALINPUTSIGNALPIPE_H
#define CONDITIONALINPUTSIGNALPIPE_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class ConditionalInputSignalPipe:public SignalProcessor
{
public:
    ConditionalInputSignalPipe();
    void feedData(QVector<double> dat, int counter, int channel);
    void feedBoolData(bool dat, int counter, int channel);
    int currentCounter;
    QVector<double> datchan1;
    QVector<double> datchan2;
    bool tempbol;
    bool dat1set;
    bool dat2set;
    bool bolset;
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class ConditionalInputSignalPipeProvider:public PipeProcessGraphicsProvider{
public:
    ConditionalInputSignalPipeProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance(QString name);
    QString getName();
};

#endif // CONDITIONALINPUTSIGNALPIPE_H
