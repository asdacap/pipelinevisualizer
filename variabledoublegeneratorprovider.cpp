#include "variabledoublegeneratorprovider.h"
#include "ui_variabledoublegeneratorprovider.h"
#include "variabledoublegeneratorproviderdialog.h"
#include "widgetedprocessgraphics.h"

VariableDoubleGeneratorProvider::VariableDoubleGeneratorProvider(MainWindow* mw, PVisual* pv)

{
    MW=mw;
    PV=pv;
}

VariableDoubleGeneratorProvider::~VariableDoubleGeneratorProvider()
{
}

ProcessGraphics* VariableDoubleGeneratorProvider::newInstance(){
    VariableDoubleGeneratorProviderDialog* dialog=new VariableDoubleGeneratorProviderDialog(nameCandidate());
    if(dialog->exec()==QDialog::Accepted){
    QString name=dialog->getName();
    double Maxim=dialog->getMaximum();
    double Minim=dialog->getMinimum();
    double Increment=dialog->getIncrement();
    double Current=dialog->getCurrent();
    DoubleGenerator* dg=new DoubleGenerator();
    MW->registerVariable(dg,Minim,Maxim,Current,Increment,name);
    ProcessGraphics* pg=new WidgetedProcessGraphics(dg,name,1,0,0,1,0,0,PV);
    return pg;
    }
    return 0;
}

QString VariableDoubleGeneratorProvider::getName(){
    return "Variable Double Generator Provider";
}
