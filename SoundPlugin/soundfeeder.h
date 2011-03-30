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

#ifndef SOUNDFEEDER_H
#define SOUNDFEEDER_H
#include "signalprocessor.h"
#include <QTimer>
#include <QBuffer>
#include "pipeproviderprovider.h"
#include "portaudio.h"
#include "QQueue"

class SoundFeeder:public QIODevice,public SignalProcessor
{
    Q_OBJECT

public:
    SoundFeeder();
    void start();
    void stop();
    bool isStarted();

private:
    int curcounter;
    PaStream* thestream;
    bool isStreamOk;
    QQueue<char> mydata;
    QTimer* timer;

protected:
   qint64 writeData(const char *data, qint64 len);
   qint64 readData(char *data, qint64 maxlen);
   qint64 bytesAvailable();

public slots:
   void timerElapsed();
   //void auStateChanged(QAudio::State s);
};

class SoundFeederProvider:public PipeProcessGraphicsProvider{
public:
    SoundFeederProvider(PVisual* pvs);
    QString getName();
    ProcessGraphics* newInstance(QString text);
    QString getToolTip();
    PVisual* pv;
};

#endif // SOUNDFEEDER_H
