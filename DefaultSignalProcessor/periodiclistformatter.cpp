#include "periodiclistformatter.h"
#include "sppropertydialog.h"
#include "processgraphics.h"
#include "widgetedprocessgraphics.h"

PeriodicListFormatter::PeriodicListFormatter(int length){
    setOutputNum(1);
    enableHelper(1,0,0);
    curdat=QVector<double>(length,0);
    offset=0;
}

void PeriodicListFormatter::feedData(QVector<QVector<double> > dat,
                                     QVector<double> doubdat,
                                     QVector<bool> booldat,
                                     int counter){
    QVector<double> data=dat.at(0);
    int i=0;
    while(i<data.count()){
        feedBuffer(data[i]);
        i=i+1;
    }

    output_collection.at(0)->feedData(curdat,counter);
}

void PeriodicListFormatter::feedBuffer(double dat){
    if(offset>=curdat.count()){
        offset=0;
    }
    curdat.replace(offset,dat);
    offset=offset+1;
}

PeriodicListFormatterProvider::PeriodicListFormatterProvider(PVisual *pv){
    PV=pv;
}

ProcessGraphics* PeriodicListFormatterProvider::newInstance(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["ListLength"]="1000";
    SPPropertyDialog* settingdialog=new SPPropertyDialog(setting);
    if(settingdialog->exec()==settingdialog->Accepted){
        return newInstance(settingdialog->getSetting());
    }
}

QMap<QString,QString> PeriodicListFormatterProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    PeriodicListFormatter* finstance=(PeriodicListFormatter*)pg->getProcessor();
    setting["ListLength"]=QVariant(finstance->getLength()).toString();
    return setting;
}

ProcessGraphics* PeriodicListFormatterProvider::newInstance(QMap<QString, QString> setting){
    QString name=setting["Name"];
    int length=QVariant(setting["ListLength"]).toInt();
    PeriodicListFormatter* sp=new PeriodicListFormatter(length);
    return new WidgetedProcessGraphics(sp,name,1,1,0,0,0,0,PV,this);
}

QString PeriodicListFormatterProvider::getName(){
    return "PeriodicListFormatter";
}
