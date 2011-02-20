#include "soundsink.h"
#include <iostream>
#include "QInputDialog"

SoundSink::SoundSink():QIODevice(),SignalProcessor()
{
    QAudioFormat format;
   // set up the format you want, eg.
   format.setFrequency(SAMPLING_FREQ);
   //format.setSampleRate(SAMPLING_FREQ);
   format.setChannels(1);
   format.setSampleSize(16);
   format.setCodec("audio/pcm");
   format.setByteOrder(QAudioFormat::BigEndian);
   format.setSampleType(QAudioFormat::SignedInt);

   QAudioDeviceInfo info = QAudioDeviceInfo::defaultOutputDevice();
   if (!info.isFormatSupported(format)) {
       std::cout<<"Unsopported format"<<std::endl;
       format = info.nearestFormat(format);
   }
   timer=new QTimer();
   timer->setSingleShot(false);
   timer->setInterval(500);
   QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
   timer->start();
   enable=true;
    out=new QAudioOutput(format,this);
    //out->setBufferSize(1024*20);
    open(QIODevice::ReadWrite);
}

SoundSink::~SoundSink(){
    //out->stop();
    //close();
}

bool SoundSink::isStarted(){
    return (out->state()==QAudio::ActiveState);
}

void SoundSink::start(){
    out->start(this);
}

void SoundSink::stop(){
    out->stop();
}

void SoundSink::timerElapsed(){
    if(out->error()==QAudio::NoError){
    }else{
        debugMessage("error"+out->error());
        out->start(this);
    }
}

void SoundSink::feedData(QVector<double> dat, int counter, int channel){
    if(!enable){
        debugMessage("Not enabled");
        return;
    }

    int i=0;
    double* rdat=dat.data();
    while(i<dat.count()){
        qint16 cdat=(qint16)(int)rdat[i];
        char* rawc=(char*)&cdat;
        mydata.enqueue(rawc[0]);
        mydata.enqueue(rawc[1]);
        i=i+1;
    }
    //std::cout<<"feeding sound"<<std::endl;
    emit readyRead();
}

qint64 SoundSink::writeData(const char *data, qint64 len){
    int i=0;
    while(i<len){
        mydata.enqueue(data[i]);
        i=i+1;
    }
    return len;
}

qint64 SoundSink::readData(char *data, qint64 maxlen){
    int i=0;
    while(i<maxlen&&mydata.count()!=0){
        data[i]=mydata.dequeue();
        i=i+1;
    }

    return i;
}

void SoundSink::setEnabled(bool en){
    enable=en;
}

qint64 SoundSink::bytesAvailable(){
    return mydata.count()+QIODevice::bytesAvailable();
}

SoundSinkProvider::SoundSinkProvider(PVisual *pvs){
    pv=pvs;
}

QString SoundSinkProvider::getName(){
    return "SoundSink";
}

ProcessGraphics* SoundSinkProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         SoundSink* sf=new SoundSink();
         ProcessGraphics* pg=new ProcessGraphics(sf,text,1,0,0,0,0,0,pv);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}
