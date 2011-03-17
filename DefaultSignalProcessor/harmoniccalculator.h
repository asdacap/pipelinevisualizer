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

#ifndef HARMONICCALCULATOR_H
#define HARMONICCALCULATOR_H
#include "signalpipe.h"
#include "doubleindexvector.h"
#include "constSetting.h"
#include "signalprocessor.h"

class HarmonicCalculator:public SignalProcessor
{
public:
    HarmonicCalculator();
    virtual double sumIt(DoubleIndexVector* ind,double index);
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
    double interval;
};

#endif // HARMONICCALCULATOR_H
