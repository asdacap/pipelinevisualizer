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
