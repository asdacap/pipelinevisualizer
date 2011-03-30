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
#include "templateproxy.h"
#include "templateprocessor.h"
#include "widgetedprocessgraphics.h"

TemplateProxy::TemplateProxy(int sout, int dout, int bout, int sin, int din, int bin){
    setOutputNum(sout);
    setBoolOutputNum(bout);
    setDoubleOutputNum(dout);
    this->sin=sin;
    this->din=din;
    this->bin=bin;
    thetarget=0;
}

void TemplateProxy::feedData(QVector<double> dat, int counter, int channel){
    if(thetarget==0)return;
    TemplateProcessor* tp=(TemplateProcessor*)thetarget;
    tp->output_collection.at(channel)->feedData(dat,counter);
}

void TemplateProxy::feedDoubleData(double dat, int counter, int channel){
    if(thetarget==0)return;
    TemplateProcessor* tp=(TemplateProcessor*)thetarget;
    tp->double_output_collection.at(channel)->feedDoubleData(dat,counter);
}

void TemplateProxy::feedBoolData(bool dat, int counter, int channel){
    if(thetarget==0)return;
    TemplateProcessor* tp=(TemplateProcessor*)thetarget;
    tp->bool_output_collection.at(channel)->feedBoolData(dat,counter);
}

QMap<QString,QString> TemplateProxyProvider::getSettings(ProcessGraphics *pg){
    TemplateProxy* theproxy=(TemplateProxy*)pg->getProcessor();
    QMap<QString,QString> thesetting;
    thesetting["SignalInput"]=QVariant(theproxy->getSignalInputNum()).toString();
    thesetting["SignalOutput"]=QVariant(theproxy->getSignalOutputNum()).toString();
    thesetting["DoubleInput"]=QVariant(theproxy->getDoubleInputNum()).toString();
    thesetting["DoubleOutput"]=QVariant(theproxy->getDoubleOutputNum()).toString();
    thesetting["BooleanInput"]=QVariant(theproxy->getBoolInputNum()).toString();
    thesetting["BooleanOutput"]=QVariant(theproxy->getBoolOutputNum()).toString();
    return thesetting;
}

QString TemplateProxyProvider::getName(){
    return "TemplateProxy";
}

QMap<QString,QString> TemplateProxyProvider::defaultSetting(){
    QMap<QString,QString> thesetting;
    thesetting["SignalInput"]="1";
    thesetting["SignalOutput"]="1";
    thesetting["DoubleInput"]="0";
    thesetting["DoubleOutput"]="0";
    thesetting["BooleanInput"]="0";
    thesetting["BooleanOutput"]="0";
    return thesetting;
}

ProcessGraphics* TemplateProxyProvider::newInstance(QMap<QString, QString> setting){
    int sinput=QVariant(setting["SignalInput"]).toInt();
    int soutput=QVariant(setting["SignalOutput"]).toInt();
    int dinput=QVariant(setting["DoubleInput"]).toInt();
    int doutput=QVariant(setting["DoubleOutput"]).toInt();
    int binput=QVariant(setting["BooleanInput"]).toInt();
    int boutput=QVariant(setting["BooleanOutput"]).toInt();
    TemplateProxy* tp=new TemplateProxy(soutput,doutput,boutput,sinput,dinput,binput);
    return new WidgetedProcessGraphics(tp,"TemplateProxy",sinput,soutput,dinput,doutput,binput,boutput,pv,this);
}
