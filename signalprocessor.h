#ifndef SIGNALPROCESSOR_H
#define SIGNALPROCESSOR_H
#include <QVector>
#include <QString>

typedef struct SignalProcessor SignalProcessor;

class SPWrapper{
public:
    SignalProcessor* sp;
    int channel;
};


class SignalDistributer{
public:
    SignalDistributer();
    void addOutput(SignalProcessor* proc,int channel);
    void removeOutput(SignalProcessor* proc,int channel);
    void feedData(QVector<double> dat,int counter);
    bool isExist(SignalProcessor* proc,int channel);
private:
    QList<SPWrapper*> collec;
};


class SignalProcessor
{
public:
    SignalProcessor(int OutputNum);
    virtual void setOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void unsetOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedData(QVector<double> dat,int counter,int channel);
    void enableDebug(QString uniquename);
    void debugMessage(QString mess);
protected:
    QString uname;
    bool debugEnab;
    QList<SignalDistributer*> output_collection;
};

#endif // SIGNALPROCESSOR_H
