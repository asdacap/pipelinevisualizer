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

#include "soundsink.h"
#include <iostream>
#include "QInputDialog"
#include "widgetedprocessgraphics.h"
#define SAMPLE_RATE (22050)

int soundSinkCallback( const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData )
{
    SoundSink* thesink=(SoundSink*)userData;
    if(thesink->bytesAvailable()/4<framesPerBuffer){
        int i=0;
        char* inchar=(char*)outputBuffer;
        while(i<framesPerBuffer*4){
            inchar[i]=0;
            i=i+1;
        }
        return paContinue;
    }
    thesink->readData((char*)outputBuffer,framesPerBuffer*4);
    return 0;
}

SoundSink::SoundSink():QIODevice(),SignalProcessor()
{
    timer=new QTimer();
    timer->setSingleShot(false);
    timer->setInterval(500);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
    timer->start();
    enable=true;
    open(QIODevice::ReadWrite);
    PaError err;
    PaDeviceIndex theinputindex=Pa_GetDefaultOutputDevice();
    const PaDeviceInfo* dinfo=Pa_GetDeviceInfo(theinputindex);
    PaStreamParameters* theparam=new PaStreamParameters();
    theparam->channelCount=1;
    theparam->device=theinputindex;
    theparam->sampleFormat=paFloat32;
    theparam->suggestedLatency=dinfo->defaultLowOutputLatency;
    err = Pa_OpenStream( &thestream,
                               0,
                               (const PaStreamParameters*)theparam,
                               SAMPLE_RATE,
                               0,
                               0,
                               soundSinkCallback,
                               this );
    if( err != paNoError ) {
        std::cout<<"Fail to initialize stream errorcode "<<err<<std::endl;
    }

    open(QBuffer::WriteOnly);
}

SoundSink::~SoundSink(){

}

bool SoundSink::isStarted(){
    return Pa_IsStreamActive(thestream);
}

void SoundSink::start(){
    Pa_StartStream(thestream);
    debugMessage("Start");
}

void SoundSink::stop(){
    Pa_StopStream(thestream);
    debugMessage("Stop");
}

void SoundSink::timerElapsed(){
    //Handle periodic error detection.
}

void SoundSink::feedData(QVector<double> dat, int counter, int channel){
    if(!enable){
        debugMessage("Not enabled");
        return;
    }

    int i=0;
    double* rdat=dat.data();
    while(i<dat.count()){
        float cdat=(float)rdat[i];
        char* rawc=(char*)&cdat;
        mydata.enqueue(rawc[0]);
        mydata.enqueue(rawc[1]);
        mydata.enqueue(rawc[2]);
        mydata.enqueue(rawc[3]);
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

SoundSinkProvider::SoundSinkProvider(PVisual *pvs):PipeProcessGraphicsProvider(pvs){
    pv=pvs;
}

QString SoundSinkProvider::getName(){
    return "SoundSink";
}

ProcessGraphics* SoundSinkProvider::newInstance(QString text){

    SoundSink* sf=new SoundSink();
    ProcessGraphics* pg=new WidgetedProcessGraphics(sf,text,1,0,0,0,0,0,pv,this);
    return pg;
}


