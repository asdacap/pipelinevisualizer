#ifndef SOUNDFEEDER_H
#define SOUNDFEEDER_H
#include "signalprocessor.h"
#include <QTimer>
#include <QtMultimedia/QAudioInput>
#include <QBuffer>
#include "pipeproviderprovider.h"

class SoundFeeder:QIODevice,public SignalProcessor
{
    Q_OBJECT

public:
    SoundFeeder();
    void start();

private:
    int curcounter;
   QAudioInput* inputAu;

protected:
   qint64 writeData(const char *data, qint64 len);
   qint64 readData(char *data, qint64 maxlen);


public slots:
   void auStateChanged(QAudio::State s);
};

class SoundFeederProvider:public PipeProcessGraphicsProvider{
public:
    SoundFeederProvider(PVisual* pvs);
    QString getName();
    ProcessGraphics* newInstance();
    PVisual* pv;
};

#endif // SOUNDFEEDER_H
