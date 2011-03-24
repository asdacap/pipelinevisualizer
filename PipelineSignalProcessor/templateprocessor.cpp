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
