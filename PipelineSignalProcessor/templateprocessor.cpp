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
#include "templateprocessor.h"
#include "processgraphics.h"
#include "templateproxy.h"
#include <iostream>

TemplateProcessor::TemplateProcessor(){

}

bool TemplateProcessor::Initialize(){
    ProcessGraphics* thepg=getProcessGraphics("TemplateProxy");
    if(thepg==0){
        std::cout<<"No a template profile"<<std::endl;
        return false;
    }
    SignalProcessor* thesp=thepg->getProcessor();
    TemplateProxy* theproxy=(TemplateProxy*)thesp;
    setOutputNum(theproxy->getSignalInputNum());
    setDoubleOutputNum(theproxy->getDoubleInputNum());
    setBoolOutputNum(theproxy->getBoolInputNum());
    this->theproxy=theproxy;
    theproxy->setTarget(this);
    return true;
}

void TemplateProcessor::feedData(QVector<double> dat, int counter, int channel){
    theproxy->output_collection.at(channel)->feedData(dat,counter);
}

void TemplateProcessor::feedDoubleData(double dat, int counter, int channel){
    theproxy->double_output_collection.at(channel)->feedDoubleData(dat,counter);
}

void TemplateProcessor::feedBoolData(bool dat, int counter, int channel){
    theproxy->bool_output_collection.at(channel)->feedBoolData(dat,counter);
}

TemplateProcessorProvider::TemplateProcessorProvider(QString name,PipelineProfile* profile,QList<PipeProcessGraphicsProvider*>* provlist,PVisual* pv){
    thename=name;
    theprofile=profile;
    PV=pv;
    this->provlist=provlist;
}

ProcessGraphics* TemplateProcessorProvider::newInstance(QString name){
    TemplateProcessor* tp=new TemplateProcessor();
    theprofile->InitializeIt(tp,*provlist);
    if(tp->Initialize()){
        return new WidgetedProcessGraphics(tp,
                                           name,
                                           tp->getSignalInputNum(),
                                           tp->getSignalOutputNum(),
                                           tp->getDoubleInputNum(),
                                           tp->getDoubleOutputNum(),
                                           tp->getBoolInputNum(),
                                           tp->getBoolOutputNum(),
                                           PV,
                                           this);
    }else{
        delete tp;
        return 0;
    }
}
