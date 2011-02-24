#include "constantdoublegeneratorprovider.h"
#include "processgraphics.h"
#include "widgetedprocessgraphics.h"

ConstantDoubleGeneratorProvider::ConstantDoubleGeneratorProvider(PVisual* pv)
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
