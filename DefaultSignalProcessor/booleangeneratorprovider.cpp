#include "booleangeneratorprovider.h"
#include "QInputDialog"
#include <iostream>
#include "widgetedprocessgraphics.h"
#include "QCheckBox"

BooleanGeneratorProvider::BooleanGeneratorProvider( PVisual *pv){
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
