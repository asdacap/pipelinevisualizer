#include "pipeproviderprovider.h"
#include "QInputDialog"
#include "iostream"
#include "QVariant"
#include "processgraphics.h"

PipeProcessGraphicsProvider::PipeProcessGraphicsProvider(){
    counter=0;
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         return newInstance(text);
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
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
