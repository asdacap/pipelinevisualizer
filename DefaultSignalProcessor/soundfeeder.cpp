#include "soundfeeder.h"
#include <iostream>
#include "QFile"
#include "util.h"
#include "QDateTime"
#include "constSetting.h"
#include "QInputDialog"
#include "widgetedprocessgraphics.h"

SoundFeeder::SoundFeeder():QIODevice(),SignalProcessor()
{
    setOutputNum(1);
    curcounter=0;
    QAudioFormat format;
   // set up the format you want, eg.
   format.setFrequency(SAMPLING_FREQ);
   format.setChannels(1);
   format.setSampleSize(16);
   format.setCodec("audio/pcm");
   format.setByteOrder(QAudioFormat::BigEndian);
   format.setSampleType(QAudioFormat::SignedInt);

   QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
   if (!info.isFormatSupported(format)) {
       std::cout<<"Unsopported format"<<std::endl;
       format = info.nearestFormat(format);
   }


    inputAu=new QAudioInput(format,this);
    QObject::connect(inputAu,SIGNAL(stateChanged(QAudio::State)),this,SLOT(auStateChanged(QAudio::State)));

}

void SoundFeeder::start(){
    debugMessage("Start");
    open(QBuffer::WriteOnly);
    inputAu->start(this);
}

qint64 SoundFeeder::writeData(const char *data, qint64 len){
    long bytegiven=len;
    double* doubdata=new double[len/2];
    intToDouble((qint16*)data,len/2,doubdata);

    int length=bytegiven/2;
    QVector<double> dat(length);
    int i=0;
    while(i<dat.count()){
        dat.replace(i,doubdata[i]);
        i=i+1;
    }
    output_collection.at(0)->feedData(dat,curcounter);
    delete []doubdata;

    curcounter=curcounter+1;
    return len;
}

qint64 SoundFeeder::readData(char *data, qint64 maxlen){
    return 0;
}

void SoundFeeder::auStateChanged(QAudio::State s){

    QString message;
    switch(s){
    case QAudio::ActiveState:message="active";break;
    case QAudio::SuspendedState:message="suspended";break;
    case QAudio::StoppedState:message="stopped";break;
    case QAudio::IdleState:message="idle";break;
    }
    debugMessage("state changed:"+QString(message));
}

void SoundFeeder::stop(){
    debugMessage("Stopped");
    inputAu->stop();
}

bool SoundFeeder::isStarted(){

    return (inputAu->state()==QAudio::ActiveState);
}

SoundFeederProvider::SoundFeederProvider(PVisual *pvs){
    pv=pvs;
}

QString SoundFeederProvider::getName(){
    return "SoundFeeder";
}

ProcessGraphics* SoundFeederProvider::newInstance(QString text){

         SoundFeeder* sf=new SoundFeeder();
         ProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,0,1,0,0,0,0,pv,this);
         return pg;

}

QString SoundFeederProvider::getToolTip(){
    return "Sound feeder will output sound on signal output sound from the sistem default microphone";
}
