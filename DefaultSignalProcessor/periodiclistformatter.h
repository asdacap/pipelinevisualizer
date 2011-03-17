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

#ifndef PERIODICLISTFORMATTER_H
#define PERIODICLISTFORMATTER_H
#include "signalprocessor.h"
#include "pvisual.h"

class PeriodicListFormatter:public SignalProcessor
{
public:
    PeriodicListFormatter(int length);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    void feedBuffer(double dat);
    int getLength(){return curdat.count();}
private:
    int offset;
    QVector<double> curdat;
};

class PeriodicListFormatterProvider: public PipeProcessGraphicsProvider{
public:
    PeriodicListFormatterProvider(PVisual* pv);
    PVisual* PV;
    ProcessGraphics* newInstance();
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    QString getName();
};

#endif // PERIODICLISTFORMATTER_H
