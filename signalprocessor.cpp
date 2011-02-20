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

void SignalDistributer::feedBoolData(bool dat, int counter){
    int i=0;
    while(i<collec.count()){
        SPWrapper* wrap=collec.at(i);
        wrap->sp->feedBoolData(dat,counter,wrap->channel);

        i=i+1;
    }
}

void SignalDistributer::feedDoubleData(double dat, int counter){
    int i=0;
    while(i<collec.count()){
        SPWrapper* wrap=collec.at(i);
        wrap->sp->feedDoubleData(dat,counter,wrap->channel);

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
    helperEnab=false;
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

void SignalProcessor::feedDoubleData(double dat, int counter, int channel){
    if(helperEnab){
        if(channel>=doubinput||channel<0){
            debugMessage("Helper funtion error, double input channel out of bound");
            return;
        }
        double* datp=new double();
        *datp=dat;
        int channelnum=channel+siginput;
        thekeeper->addKey(channelnum,counter,datp);
        if(thekeeper->isAvail(counter)){
            dataReady(counter);
        }
    }
}

void SignalProcessor::feedBoolData(bool dat, int counter, int channel){
    if(helperEnab){
        if(channel>=boolinput||channel<0){
            debugMessage("Helper funtion error, bool input channel out of bound");
            return;
        }
        bool* boolp=new bool();
        *boolp=dat;
        int channelnum=channel+siginput+doubinput;
        thekeeper->addKey(channelnum,counter,boolp);
        if(thekeeper->isAvail(counter)){
            dataReady(counter);
        }
    }
}

void SignalProcessor::feedData(QVector<double> dat, int counter, int channel){
    if(helperEnab){
        if(channel>=siginput||channel<0){
            debugMessage("Helper funtion error, signal input channel out of bound");
            return;
        }
        QVector<double>* datp=new QVector<double>(dat);
        thekeeper->addKey(channel,counter,datp);
        if(thekeeper->isAvail(counter)){
            dataReady(counter);
        }
    }
}

void SignalProcessor::dataReady(int counter){
    void** data=thekeeper->getObject(counter);
    QVector<QVector<double> > sigdat;
    QVector<double> doubdat;
    QVector<bool> booldat;
    int i=0;
    while(i<thekeeper->theLength()){
        if(i<siginput){
            QVector<double>* dat=(QVector<double>*)data[i];
            sigdat.append(*dat);
            delete dat;
        }else if(i<doubinput+siginput){
            double* dat=(double*)data[i];
            doubdat.append(*dat);
            delete dat;
        }else{
            bool* dat=(bool*)data[i];
            booldat.append(*dat);
            delete dat;
        }
        i=i+1;
    }
    delete [] data;
    feedData(sigdat,doubdat,booldat,counter);
}

void SignalProcessor::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat,int counter){

}

void SignalProcessor::setDoubleOutputNum(int num){
    int i=0;
    while(i<num){
        SignalDistributer* sdist=new SignalDistributer();
        double_output_collection.append(sdist);
        i=i+1;
    }
}

void SignalProcessor::enableHelper(int siginput,int doubinput,int boolinput){
    helperEnab=true;
    this->siginput=siginput;
    this->doubinput=doubinput;
    this->boolinput=boolinput;
    thekeeper=new CounterKeeper(siginput+doubinput+boolinput);
}

void SignalProcessor::start(){

}

void SignalProcessor::stop(){

}

bool SignalProcessor::isStarted(){
    return true;
}
