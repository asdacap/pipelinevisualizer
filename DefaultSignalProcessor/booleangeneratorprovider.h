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

#ifndef BOOLEANGENERATORPROVIDER_H
#define BOOLEANGENERATORPROVIDER_H
#include "booleangenerator.h"
#include "pipeproviderprovider.h"

class PVisual;

class BooleanGeneratorProvider:public PipeProcessGraphicsProvider
{
public:
    BooleanGeneratorProvider(PVisual* pv);
    QString getName();
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString,QString> setting);

    PVisual* PV;
};

#endif // BOOLEANGENERATORPROVIDER_H
