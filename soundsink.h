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
    QString getName();
    ProcessGraphics* newInstance();
};

#endif // SOUNDSINK_H
