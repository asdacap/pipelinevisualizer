#include "variabledoublegeneratorprovider.h"
#include "ui_variabledoublegeneratorprovider.h"
#include "variabledoublegeneratorproviderdialog.h"
#include "widgetedprocessgraphics.h"
#include "qwt_slider.h"

VariableDoubleGeneratorProvider::VariableDoubleGeneratorProvider( PVisual* pv)

{
    PV=pv;
}

VariableDoubleGeneratorProvider::~VariableDoubleGeneratorProvider()
{
}

ProcessGraphics* VariableDoubleGeneratorProvider::newInstance(){
    VariableDoubleGeneratorProviderDialog* dialog=new VariableDoubleGeneratorProviderDialog(nameCandidate());
    if(dialog->exec()==QDialog::Accepted){
    QString name=dialog->getName();
    double max=dialog->getMaximum();
    double min=dialog->getMinimum();
    double increm=dialog->getIncrement();
    double cur=dialog->getCurrent();
    DoubleGenerator* dg=new DoubleGenerator();
    //
    QwtSlider* propslider=new QwtSlider(0,Qt::Horizontal,QwtSlider::TopScale,QwtSlider::BgTrough);
    propslider->setRange(min,max,increm,1);
    propslider->setThumbWidth(10);
    propslider->setToolTip(name);
    QObject::connect(propslider,SIGNAL(valueChanged(double)),dg,SLOT(setValue(double)));
    propslider->setValue(cur);
    //

    ProcessGraphics* pg=new WidgetedProcessGraphics(dg,name,1,0,0,1,0,0,PV,this,propslider,QRect(0,0,500,40));
    return pg;
    }
    return 0;
}

QString VariableDoubleGeneratorProvider::getName(){
    return "Variable Double Generator Provider";
}

QMap<QString,QString> VariableDoubleGeneratorProvider::getSettings(ProcessGraphics *pg){
    WidgetedProcessGraphics* widgeted=(WidgetedProcessGraphics*)pg;
    QwtSlider* slider=(QwtSlider*)widgeted->getWidget();
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    setting["Maximum"]=slider->maxValue();
    setting["Minimum"]=slider->minValue();
    setting["Increment"]=slider->step();
    setting["Current"]=slider->value();
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
    QwtSlider* propslider=new QwtSlider(0,Qt::Horizontal,QwtSlider::TopScale,QwtSlider::BgTrough);
    propslider->setRange(min,max,increm,1);
    propslider->setThumbWidth(10);
    propslider->setToolTip(name);
    QObject::connect(propslider,SIGNAL(valueChanged(double)),dg,SLOT(setValue(double)));
    propslider->setValue(cur);
    //

    ProcessGraphics* pg=new WidgetedProcessGraphics(dg,name,1,0,0,1,0,0,PV,this,propslider,QRect(0,0,500,40));
    return pg;
}
