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

#include "booleangenerator.h"

BooleanGenerator::BooleanGenerator():SignalProcessor()
{
    cdat=0;
    enableHelper(1,0,0);
    setBoolOutputNum(1);
}

void BooleanGenerator::setValue(bool val){
    cdat=val;
}

bool BooleanGenerator::getValue(){
    return cdat;
}

void BooleanGenerator::feedData(QVector<double> dat, int counter, int channel){
    bool_output_collection.at(0)->feedBoolData(getValue(),counter);
}
