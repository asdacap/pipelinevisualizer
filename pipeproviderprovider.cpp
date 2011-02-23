#include "pipeproviderprovider.h"
#include "QInputDialog"
#include "iostream"
#include "QVariant"
#include "processgraphics.h"
#include "sppropertydialog.h"

PipeProcessGraphicsProvider::PipeProcessGraphicsProvider(){
    counter=0;
}

QMap<QString,QString> PipeProcessGraphicsProvider::defaultSetting(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    return setting;
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(){
    QMap<QString,QString> setting=defaultSetting();
    SPPropertyDialog dialog(setting);
    if(dialog.exec()){
        return newInstance(dialog.getSetting());
    }else{
        return 0;
    }

}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(QString name){
    return 0;
}

QString PipeProcessGraphicsProvider::nameCandidate(){
    counter=counter+1;
    return getName()+QVariant(counter).toString();
}

QMap<QString,QString> PipeProcessGraphicsProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> settings;
    settings["Name"]=pg->getName();
    return settings;
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(QMap<QString, QString> setting){
    return newInstance(setting["Name"]);
}

QString PipeProcessGraphicsProvider::getToolTip(){
    return "";
}

QString PipeProcessGraphicsProvider::getProviderToolTip(int id){
    return "";
}

QString PipeProcessGraphicsProvider::getTargetToolTip(int id){
    return "";
}
