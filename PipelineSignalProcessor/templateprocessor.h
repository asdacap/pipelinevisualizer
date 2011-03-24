#ifndef TEMPLATEPROCESSOR_H
#define TEMPLATEPROCESSOR_H
#include "signalprocessor.h"
#include "templateproxy.h"
#include "pvisual.h"
#include "pipelineprofile.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class TemplateProcessor:public SignalProcessor,public PVisual
{
public:
    TemplateProcessor();
    bool Initialize();
    int getSignalOutputNum(){return output_collection.count();}
    int getDoubleOutputNum(){return double_output_collection.count();}
    int getBoolOutputNum(){return bool_output_collection.count();}
    int getSignalInputNum(){return theproxy->getSignalOutputNum();}
    int getDoubleInputNum(){return theproxy->getDoubleOutputNum();}
    int getBoolInputNum(){return theproxy->getBoolOutputNum();}

    void feedData(QVector<double> dat, int counter, int channel);
    void feedDoubleData(double dat, int counter, int channel);
    void feedBoolData(bool dat, int counter, int channel);
private:
    TemplateProxy* theproxy;
    friend class TemplateProxy;
};

class TemplateProcessorProvider:public PipeProcessGraphicsProvider{
public:
    TemplateProcessorProvider(QString name,PipelineProfile* profile,QList<PipeProcessGraphicsProvider*>* provlist,PVisual* pv);
    QString getName(){return thename;}
    ProcessGraphics* newInstance(QString name);
private:
    QString thename;
    PVisual* PV;
    QList<PipeProcessGraphicsProvider*>* provlist;
    PipelineProfile* theprofile;
};

#endif // TEMPLATEPROCESSOR_H
