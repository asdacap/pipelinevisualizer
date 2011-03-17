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

#ifndef BLOCKGENERATOR_H
#define BLOCKGENERATOR_H
#include "signalprocessor.h"
#include "doublegenerator.h"
#include "pipeproviderprovider.h"

class BlockGenerator:public SignalProcessor
{
public:
    BlockGenerator(double dat,int length);
    BlockGenerator();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    double getValue(){return val;}
    double getLength(){return leng;}
private:
    bool constantmode;
    double val;
    double leng;
};

class VariableBlockGenerator:public PipeProcessGraphicsProvider{
public:
    VariableBlockGenerator(PVisual* pv);
    PVisual* PV;
    QString getName(){return "VariableBlockGenerator";}
    ProcessGraphics* newInstance(QString name);
};

class ConstantBlockGenerator:public PipeProcessGraphicsProvider{
public:
    ConstantBlockGenerator(PVisual* pv);
    PVisual* PV;
    QString getName(){return "ConstantBlockGenerator";}
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
};

#endif // BLOCKGENERATOR_H
