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

#ifndef BLOCKLENGTHSENDER_H
#define BLOCKLENGTHSENDER_H
#include "signalprocessor.h"

class BlockLengthSender:public SignalProcessor
{
public:
    BlockLengthSender();
    void feedData(QVector<double> dat, int counter, int channel);
};

#endif // BLOCKLENGTHSENDER_H
