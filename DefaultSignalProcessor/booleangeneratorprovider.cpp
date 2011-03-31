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

#include "booleangeneratorprovider.h"
#include "QInputDialog"
#include <iostream>
#include "widgetedprocessgraphics.h"
#include "QCheckBox"

BooleanGeneratorProvider::BooleanGeneratorProvider( PVisual *pv):PipeProcessGraphicsProvider(pv){
    PV=pv;
}

QString BooleanGeneratorProvider::getName(){
    return "BooleanGenerator";
}

ProcessGraphics* BooleanGeneratorProvider::newInstance(QMap<QString,QString> setting){

    QString text=setting["Name"];
    BooleanGenerator* sf=new BooleanGenerator();
    sf->setValue(setting["Checked"]=="true");
    QCheckBox* cbox=new QCheckBox(text,0);
    cbox->setChecked(sf->getValue());
    QObject::connect(cbox,SIGNAL(toggled(bool)),sf,SLOT(setValue(bool)));
    ProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,1,0,0,0,0,1,PV,this,cbox,QRect(0,0,
                                                                                           cbox->fontMetrics().width(text)+20
                                                                                           ,15));
    return pg;
}

QMap<QString,QString> BooleanGeneratorProvider::defaultSetting(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["Checked"]="true";
    return setting;
}

QMap<QString,QString> BooleanGeneratorProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    WidgetedProcessGraphics* wpg=(WidgetedProcessGraphics*)pg;
    QCheckBox* check=(QCheckBox*)wpg->getWidget();
    if(check->isChecked()){
        setting["Checked"]="true";
    }else{
        setting["Checked"]="false";
    }
    return setting;
}
