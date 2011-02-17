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

SignalProcessor::SignalProcessor(int OutputNum){
    debugEnab=false;
    int i=0;
    while(i<OutputNum){
        SignalDistributer* sdist=new SignalDistributer();
        output_collection.append(sdist);
        i=i+1;
    }
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
