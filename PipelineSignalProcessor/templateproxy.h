#ifndef TEMPLATEPROXY_H
#define TEMPLATEPROXY_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"

class TemplateProcessor;

class TemplateProxy:public SignalProcessor
{
public:
    TemplateProxy(int sout,int dout,int bout,int sin,int din,int bin);
    void setTarget(SignalProcessor* thetarget){
        this->thetarget=thetarget;
    }

    void feedData(QVector<double> dat, int counter, int channel);
    void feedDoubleData(double dat, int counter, int channel);
    void feedBoolData(bool dat, int counter, int channel);

    int getSignalOutputNum(){return output_collection.count();}
    int getDoubleOutputNum(){return double_output_collection.count();}
    int getBoolOutputNum(){return bool_output_collection.count();}
    int getSignalInputNum(){return sin;}
    int getDoubleInputNum(){return din;}
    int getBoolInputNum(){return bin;}

private:
    int sin;
    int din;
    int bin;
    SignalProcessor* thetarget;

    friend class TemplateProcessor;
};

class TemplateProxyProvider:public PipeProcessGraphicsProvider{
public:
    PVisual* pv;
    TemplateProxyProvider(PVisual* pv){this->pv=pv;}
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    QMap<QString,QString> defaultSetting();
    ProcessGraphics* newInstance(QMap<QString, QString> setting);
    QString getName();
};

#endif // TEMPLATEPROXY_H
