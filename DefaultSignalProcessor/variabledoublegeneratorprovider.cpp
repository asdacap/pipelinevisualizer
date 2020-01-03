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

#include "variabledoublegeneratorprovider.h"
#include "widgetedprocessgraphics.h"
#include "qwt/qwt_slider.h"

VariableDoubleGeneratorProvider::VariableDoubleGeneratorProvider( PVisual* pv)
    :PipeProcessGraphicsProvider(pv)
{
    PV=pv;
}

VariableDoubleGeneratorProvider::~VariableDoubleGeneratorProvider()
{
}

QMap<QString,QString> VariableDoubleGeneratorProvider::defaultSetting(){
    QMap<QString,QString> res;
    res["Name"]=nameCandidate();
    res["Maximum"]="100";
    res["Minimum"]="0";
    res["Increment"]="1";
    res["Current"]="1";
    return res;
}

QString VariableDoubleGeneratorProvider::getName(){
    return "VariableDoubleGenerator";
}

QMap<QString,QString> VariableDoubleGeneratorProvider::getSettings(ProcessGraphics *pg){
    WidgetedProcessGraphics* widgeted=(WidgetedProcessGraphics*)pg;
    QwtSlider* slider=(QwtSlider*)widgeted->getWidget();
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    setting["Maximum"]=QVariant(slider->maximum()).toString();
    setting["Minimum"]=QVariant(slider->minimum()).toString();
    setting["Increment"]=QVariant(slider->scaleStepSize()).toString();
    setting["Current"]=QVariant(slider->value()).toString();
    return setting;
}

ProcessGraphics* VariableDoubleGeneratorProvider::newInstance(QMap<QString, QString> setting){
    QString name=setting["Name"];
    double max=QVariant(setting["Maximum"]).toDouble();
    double min=QVariant(setting["Minimum"]).toDouble();
    double increm=QVariant(setting["Increment"]).toDouble();
    double cur=QVariant(setting["Current"]).toDouble();
    DoubleGenerator* dg=new DoubleGenerator();
    //
    QwtSlider* propslider=new QwtSlider(Qt::Horizontal);
    propslider->setScale(min,max);
    propslider->setScaleStepSize(increm);
    propslider->setToolTip(name);
    QObject::connect(propslider,SIGNAL(valueChanged(double)),dg,SLOT(setValue(double)));
    propslider->setValue(cur);
    //

    ProcessGraphics* pg=new WidgetedProcessGraphics(dg,name,1,0,0,1,0,0,PV,this,propslider,QRect(0,0,500,40));
    return pg;
}
