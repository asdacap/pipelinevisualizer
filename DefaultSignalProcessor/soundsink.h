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

#ifndef SOUNDSINK_H
#define SOUNDSINK_H
#include "signalprocessor.h"
#include "constSetting.h"
#include "pipeproviderprovider.h"
#include <QtMultimedia>

class SoundSink: public QIODevice, public SignalProcessor
{
    Q_OBJECT
public:
    SoundSink();
    ~SoundSink();
    void feedData(QVector<double> dat, int counter, int channel);
    qint64 writeData(const char *data, qint64 len);
    qint64 readData(char *data, qint64 maxlen);
    qint64 bytesAvailable();
    void start();
    void stop();
    bool isStarted();

private:
    QQueue<char> mydata;
    QTimer* timer;
    bool enable;
    QAudioOutput* out;
public slots:
    void setEnabled(bool en);
    void timerElapsed();
};

class SoundSinkProvider:public PipeProcessGraphicsProvider{
public:
    SoundSinkProvider(PVisual* pvs);
    QString getName();
    ProcessGraphics* newInstance(QString text);
    PVisual* pv;
};

#endif // SOUNDSINK_H
