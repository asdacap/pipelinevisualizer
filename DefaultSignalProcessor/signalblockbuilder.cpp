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

#include "signalblockbuilder.h"
#include <iostream>
#include <QDateTime>
#include "sppropertydialog.h"

SignalBlockBuilder::SignalBlockBuilder(int size,int resolu)
{
    buffsize=0;
    ct=0;
    blocksize=size;
    res=resolu;
    inbuffer=new QVector<double>(size);
    setOutputNum(1);
}

void SignalBlockBuilder::feedData(QVector<double> in,int ,int ){

    QVector<double> total(buffsize+in.count());
    int i=0;
    while(i<buffsize){
        total.replace(i,inbuffer->at(i));
        i=i+1;
    }
    i=0;
    while(i<in.count()){
        total.replace(buffsize+i,in[i]);
        i=i+1;
    }


    QVector<double> curbuf(blocksize);
    int cp;
    int counter=0;
    while((counter+blocksize)<total.count()){
        i=0;
        cp=counter;
        while(i<blocksize){
            curbuf.replace(i,total[i+(cp)]);
            i=i+1;
        }
        ct=ct+1;
        output_collection.at(0)->feedData(curbuf,ct);
        counter=counter+(blocksize/(res+1));
    }
    i=0;
    cp=counter;
    int remaining=total.count()-(cp);
    while(i<remaining){
        inbuffer->replace(i,total[i+(cp)]);
        i=i+1;
    }
    buffsize=remaining;


}

int* SignalBlockBuilder::getCounter(){
    return &ct;
}

SignalBlockBuilderProvider::SignalBlockBuilderProvider(PVisual *pv):PipeProcessGraphicsProvider(pv){
    PV=pv;
}

QString SignalBlockBuilderProvider::getName(){
    return "SignalBlockBuilder";
}

ProcessGraphics* SignalBlockBuilderProvider::newInstance(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["BlockSize"]="1024";
    setting["ExtraResolution"]="0";
    SPPropertyDialog* settingdialog=new SPPropertyDialog(setting);
    if(settingdialog->exec()==settingdialog->Accepted){
        return newInstance(settingdialog->getSetting());
    }
    return 0;
}

QMap<QString,QString> SignalBlockBuilderProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    SignalBlockBuilder* sp=(SignalBlockBuilder*)pg->getProcessor();
    setting["BlockSize"]=QVariant(sp->blocksize).toString();
    setting["ExtraResolution"]=QVariant(sp->res).toString();
    return setting;
}

ProcessGraphics* SignalBlockBuilderProvider::newInstance(QMap<QString, QString> setting){
    int blocksize=QVariant(setting["BlockSize"]).toInt();
    int extraresol=QVariant(setting["ExtraResolution"]).toInt();
    QString name=setting["Name"];
    SignalBlockBuilder* sbb=new SignalBlockBuilder(blocksize,extraresol);
    return new WidgetedProcessGraphics(sbb,name,1,1,0,0,0,0,PV,this);
}
