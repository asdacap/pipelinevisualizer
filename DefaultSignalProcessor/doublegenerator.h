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

#ifndef DOUBLEGENERATOR_H
#define DOUBLEGENERATOR_H
#include "signalprocessor.h"
#include "QObject"

class DoubleGenerator:public QObject,public SignalProcessor
{
    Q_OBJECT
public:
    DoubleGenerator(double val=0);
    void feedData(QVector<double> dat, int counter, int channel);
    virtual double getValue();
public slots:
    void setValue(double val);
private:
    double cdat;

};

#endif // DOUBLEGENERATOR_H
