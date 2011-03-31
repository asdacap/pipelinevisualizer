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

#include "soundfeeder.h"
#include <iostream>
#include "QFile"
#include "util.h"
#include "QDateTime"
#include "constSetting.h"
#include "QInputDialog"
#include "widgetedprocessgraphics.h"

#define SAMPLE_RATE (22050)

int soundFeederCallback( const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData )
{
    SoundFeeder* thefeeder=(SoundFeeder*)userData;
    QByteArray anarray((char*)inputBuffer,framesPerBuffer*4);
    thefeeder->write(anarray);
    return 0;
}

SoundFeeder::SoundFeeder():QIODevice(),SignalProcessor()
{
    setOutputNum(1);
    curcounter=0;
    timer=new QTimer();
    timer->setSingleShot(false);
    timer->setInterval(100);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
    timer->start();
    open(QIODevice::ReadWrite);
    PaError err;
    PaDeviceIndex theinputindex=Pa_GetDefaultInputDevice();
    const PaDeviceInfo* dinfo=Pa_GetDeviceInfo(theinputindex);
    PaStreamParameters* theparam=new PaStreamParameters();
    theparam->channelCount=1;
    theparam->device=theinputindex;
    theparam->sampleFormat=paFloat32;
    theparam->suggestedLatency=dinfo->defaultLowInputLatency;
    err = Pa_OpenStream( &thestream,
                               (const PaStreamParameters*)theparam,
                               0,
                               SAMPLE_RATE,
                               0,
                               0,
                               soundFeederCallback,
                               this );
    if( err != paNoError ) {
        std::cout<<"Fail to initialize stream errorcode "<<err<<std::endl;
        isStreamOk=false;
    }else{
        isStreamOk=true;
    }

    open(QBuffer::ReadWrite);

}

void SoundFeeder::start(){
    if(!isStreamOk)return;
    debugMessage("Start");
    open(QBuffer::ReadWrite);
    Pa_StartStream(thestream);
}

qint64 SoundFeeder::writeData(const char *data, qint64 len){
    int i=0;
    while(i<len){
        mydata.enqueue(data[i]);
        i=i+1;
    }
    return len;

}

qint64 SoundFeeder::readData(char *data, qint64 maxlen){
    int i=0;
    while(i<maxlen&&mydata.count()!=0){
        data[i]=mydata.dequeue();
        i=i+1;
    }

    return i;
}

void SoundFeeder::stop(){
    if(!isStreamOk)return;
    debugMessage("Stopped");
    Pa_StopStream(thestream);
}

bool SoundFeeder::isStarted(){
    if(!isStreamOk)return false;
    return Pa_IsStreamActive(thestream);
}

void SoundFeeder::timerElapsed(){

    if(bytesAvailable()<4)return;
    QVector<double> thedoubles;
    int i=0;
    while(bytesAvailable()>=4){
        float rnum=0;
        char* cpointer=(char*)&rnum;
        readData(cpointer,4);
        thedoubles.append((double)rnum);
        i=i+4;
    }

    output_collection.at(0)->feedData(thedoubles,curcounter);

    curcounter=curcounter+1;
}

qint64 SoundFeeder::bytesAvailable(){
    return mydata.count()+QIODevice::bytesAvailable();
}

SoundFeederProvider::SoundFeederProvider(PVisual *pvs):PipeProcessGraphicsProvider(pvs){
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

