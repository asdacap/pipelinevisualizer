#include "soundfeeder.h"
#include <iostream>
#include "QFile"
#include "util.h"
#include "QDateTime"
#include "constSetting.h"
#include "QInputDialog"

SoundFeeder::SoundFeeder():QIODevice(),SignalProcessor(1)
{
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

    start();
}

void SoundFeeder::start(){
    std::cout<<"Start"<<std::endl;
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

    std::string message;
    switch(s){
    case QAudio::ActiveState:message="active";break;
    case QAudio::SuspendedState:message="suspended";break;
    case QAudio::StoppedState:message="stopped";break;
    case QAudio::IdleState:message="idle";break;
    }
    std::cout<<"state changed:"<<message<<std::endl;
}

QString SoundFeederProvider::getName(){
    return "SoundFeeder";
}

ProcessGraphics* SoundFeederProvider::newInstance(){
    bool ok;
    QString text = QInputDialog::getText(0, QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              "Test", &ok);
     if (ok && !text.isEmpty()){
         SoundFeeder* sf=new SoundFeeder();
         ProcessGraphics* pg=new ProcessGraphics(sf,text,0,1);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
