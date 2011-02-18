#include "signalprocessor.h"
#include <iostream>
#include "QString"

SignalDistributer::SignalDistributer(){
    collec=QList<SPWrapper*>();
}

void SignalDistributer::feedData(QVector<double> dat, int counter){

    int i=0;
    while(i<collec.count()){
        SPWrapper* wrap=collec.at(i);
        wrap->sp->feedData(dat,counter,wrap->channel);

        i=i+1;
    }
}

bool SignalDistributer::isExist(SignalProcessor *proc, int channel){
    int i=0;
    while(i<collec.count()){
        SPWrapper* wrap=collec.at(i);
        if(wrap->sp==proc&&wrap->channel==channel){
            return true;
        }
        i=i+1;
    }
    return false;
}

void SignalDistributer::addOutput(SignalProcessor *proc, int channel){
    if(isExist(proc,channel))return;
    SPWrapper* spw=new SPWrapper();
    spw->channel=channel;
    spw->sp=proc;
    collec.append(spw);
}

void SignalDistributer::removeOutput(SignalProcessor *proc, int channel){
    int i=0;
    while(i<collec.count()){
        SPWrapper* wrap=collec.at(i);
        if(wrap->sp==proc&&wrap->channel==channel){
            delete wrap;
            collec.removeAt(i);
            return;
        }
        i=i+1;
    }
}

SignalProcessor::SignalProcessor(){
    debugEnab=false;

}

void SignalProcessor::enableDebug(QString uniquename){
    uname=uniquename;
    debugEnab=true;
}

void SignalProcessor::debugMessage(QString mess){
    if(!debugEnab)return;
    std::cout<<"Debug on:"<<uname.toStdString()<<":"<<mess.toStdString()<<std::endl;
}

void SignalProcessor::setOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=output_collection.count()){
        debugMessage("set output error invalid index");

        return;}
    int i=outchannel;
    output_collection.at(i)->addOutput(proc,inchannel);
}

void SignalProcessor::unsetOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=output_collection.count()){
        debugMessage("unset output error invalid index");
        return;}
    int i=outchannel;
    output_collection.at(i)->removeOutput(proc,inchannel);
}

void SignalProcessor::feedData(QVector<double> dat, int counter, int channel){

}

void SignalProcessor::setOutputNum(int num){
    int i=0;
    while(i<num){
        SignalDistributer* sdist=new SignalDistributer();
        output_collection.append(sdist);
        i=i+1;
    }
}

void SignalProcessor::setBoolOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=bool_output_collection.count()){
        debugMessage("set output error invalid index");

        return;}
    int i=outchannel;
    bool_output_collection.at(i)->addOutput(proc,inchannel);
}

void SignalProcessor::unsetBoolOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=bool_output_collection.count()){
        debugMessage("unset output error invalid index");
        return;}
    int i=outchannel;
    bool_output_collection.at(i)->removeOutput(proc,inchannel);
}

void SignalProcessor::feedBoolData(QVector<double> dat, int counter, int channel){

}

void SignalProcessor::setBoolOutputNum(int num){
    int i=0;
    while(i<num){
        SignalDistributer* sdist=new SignalDistributer();
        bool_output_collection.append(sdist);
        i=i+1;
    }
}

void SignalProcessor::setDoubleOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=double_output_collection.count()){
        debugMessage("set output error invalid index");

        return;}
    int i=outchannel;
    double_output_collection.at(i)->addOutput(proc,inchannel);
}

void SignalProcessor::unsetDoubleOutput(int outchannel, SignalProcessor *proc, int inchannel){
    if(outchannel>=double_output_collection.count()){
        debugMessage("unset output error invalid index");
        return;}
    int i=outchannel;
    double_output_collection.at(i)->removeOutput(proc,inchannel);
}

void SignalProcessor::feedDoubleData(QVector<double> dat, int counter, int channel){

}

void SignalProcessor::setDoubleOutputNum(int num){
    int i=0;
    while(i<num){
        SignalDistributer* sdist=new SignalDistributer();
        double_output_collection.append(sdist);
        i=i+1;
    }
}

void SignalProcessor::start(){

}

void SignalProcessor::stop(){

}
