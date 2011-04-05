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
    void setOutput(int outchannel,SignalProcessor* proc,int inchannel);
    void unsetOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedData(QVector<double> dat,int counter,int channel);
    void setOutputNum(int num);
    //Boolean Method
    void setBoolOutput(int outchannel,SignalProcessor* proc,int inchannel);
    void unsetBoolOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedBoolData(bool dat,int counter,int channel);
    void setBoolOutputNum(int num);
    //Double Method
    void setDoubleOutput(int outchannel,SignalProcessor* proc,int inchannel);
    void unsetDoubleOutput(int outchannel,SignalProcessor* proc,int inchannel);
    virtual void feedDoubleData(double dat,int counter,int channel);
    void setDoubleOutputNum(int num);

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
