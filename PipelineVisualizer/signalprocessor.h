#ifndef SIGNALPROCESSOR_H
#define SIGNALPROCESSOR_H
#include <QVector>
#include <QString>
#include "counterkeeper.h"

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
    void feedBoolData(bool dat,int counter);
    void feedDoubleData(double dat,int counter);
    bool isExist(SignalProcessor* proc,int channel);
private:
    QList<SPWrapper*> collec;
};


class SignalProcessor
{
public:
    SignalProcessor();
    //1D method
    virtual void setOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void unsetOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedData(QVector<double> dat,int counter,int channel);
    virtual void setOutputNum(int num);
    //Boolean Method
    virtual void setBoolOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void unsetBoolOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedBoolData(bool dat,int counter,int channel);
    virtual void setBoolOutputNum(int num);
    //Double Method
    virtual void setDoubleOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void unsetDoubleOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedDoubleData(double dat,int counter,int channel);
    virtual void setDoubleOutputNum(int num);

    //Helper method
    virtual void feedData(QVector<QVector<double> > dat,QVector<double> doubdat,QVector<bool> booldat,int counter);

    //Start stop interface
    virtual void start();
    virtual void stop();
    virtual bool isStarted();
    
    void enableDebug(QString uniquename);
    void enableHelper(int s,int d,int b);
    void debugMessage(QString mess);
private:
    void dataReady(int counter);
    bool helperEnab;
    CounterKeeper* thekeeper;
    int siginput;
    int doubinput;
    int boolinput;

protected:
    QString uname;
    bool debugEnab;
    QList<SignalDistributer*> output_collection;
    QList<SignalDistributer*> bool_output_collection;
    QList<SignalDistributer*> double_output_collection;
};

#endif // SIGNALPROCESSOR_H
