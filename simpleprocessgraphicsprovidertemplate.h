#ifndef SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
#define SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

template<class P>
class SimpleProcessGraphicsProviderTemplate:public PipeProcessGraphicsProvider
{
public:
    SimpleProcessGraphicsProviderTemplate(QString name,PVisual* pv,
                                          int sin,int sout,int din,int dout,
                                          int bin,int bout){
        this->name=name;
        PV=pv;
        sinput=sin;
        soutput=sout;
        dinput=din;
        doutput=dout;
        binput=bin;
        boutput=bout;
}

    QString name;
    int sinput;
    int soutput;
    int dinput;
    int doutput;
    int binput;
    int boutput;
    PVisual* PV;
    QString getName(){return name;}
    ProcessGraphics* newInstance(QString s){
        P* prov=new P();
        return new WidgetedProcessGraphics(prov,s,sinput,soutput,dinput,doutput,binput,boutput,PV,this);
    }
};

#endif // SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
