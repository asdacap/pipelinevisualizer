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

#include "constantdoublegeneratorprovider.h"
#include "processgraphics.h"
#include "widgetedprocessgraphics.h"

ConstantDoubleGeneratorProvider::ConstantDoubleGeneratorProvider(PVisual* pv):PipeProcessGraphicsProvider(pv)
{
    PV=pv;
}

QMap<QString,QString> ConstantDoubleGeneratorProvider::defaultSetting(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["Value"]="0";
    return setting;
}

QMap<QString,QString> ConstantDoubleGeneratorProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    DoubleGenerator* dg=(DoubleGenerator*)pg->getProcessor();
    setting["Value"]=QVariant(dg->getValue()).toString();
    return setting;
}

ProcessGraphics* ConstantDoubleGeneratorProvider::newInstance(QMap<QString, QString> setting){
    double value=QVariant(setting["Value"]).toDouble();
    DoubleGenerator* dg=new DoubleGenerator();
    dg->setValue(value);
    return new WidgetedProcessGraphics(dg,setting["Name"],1,0,0,1,0,0,PV,this);
}
