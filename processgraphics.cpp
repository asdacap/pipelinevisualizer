#include "processgraphics.h"
#include "signalpipetarget.h"
#include "signalpipeprovider.h"
#include "doublepipetarget.h"
#include "doublepipeprovider.h"
#include "booleanpipetarget.h"
#include "booleanpipeprovider.h"
#include "pvisual.h"

ProcessGraphics::ProcessGraphics(SignalProcessor *sp, QString name, PipeProcessGraphicsProvider *prov,
                                 int sinput, int soutput, int dinput, int doutput, int binput, int boutput,
                                 PVisual* pvi){
    processor=sp;
    pgName=name;
    provider=prov;
    pv=pvi;
    PVisual* pvis=pv;

    int i=0;
    while(i<sinput){
        SignalPipeTarget* targ=new SignalPipeTarget(i,processor,pvis->getSignalTargetCollection());
        targ->setToolTip(getProvider()->getTargetToolTip(i));
        targ->setParentItem(this);
        targetCollection.append(targ);
        signalTargetCollection.append(targ);
        i=i+1;
    }

    i=0;
    while(i<soutput){
        SignalPipeProvider* targ=new SignalPipeProvider(this,i,pvis->getSignalTargetCollection());
        targ->setToolTip(getProvider()->getProviderToolTip(i));
        targ->setParentItem(this);
        providerCollection.append(targ);
        signalProviderCollection.append(targ);
        i=i+1;
    }

    i=0;
    while(i<dinput){
        DoublePipeTarget* dtarg=new DoublePipeTarget(i,processor,pvis->getDoubleTargetCollection());
        dtarg->setToolTip(getProvider()->getTargetToolTip(i+sinput));
        dtarg->setParentItem(this);
        targetCollection.append(dtarg);
        doubleTargetCollection.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<doutput){
        DoublePipeProvider* dtarg=new DoublePipeProvider(this,i,pvis->getDoubleTargetCollection());
        dtarg->setToolTip(getProvider()->getProviderToolTip(i+soutput));
        dtarg->setParentItem(this);
        providerCollection.append(dtarg);
        doubleProviderCollection.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<binput){
        PipeTarget* dtarg=new BooleanPipeTarget(i,processor,pvis->getBoolTargetCollection());
        dtarg->setToolTip(getProvider()->getTargetToolTip(i+sinput+dinput));
        dtarg->setParentItem(this);
        targetCollection.append(dtarg);
        boolTargetCollection.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<boutput){
        BooleanPipeProvider* dtarg=new BooleanPipeProvider(this,i,pvis->getBoolTargetCollection());
        dtarg->setToolTip(getProvider()->getProviderToolTip(i+soutput+doutput));
        dtarg->setParentItem(this);
        providerCollection.append(dtarg);
        boolProviderCollection.append(dtarg);
        i=i+1;
    }
}

QRectF ProcessGraphics::boundingRect() const{
    return QRectF();
}

void ProcessGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

void ProcessGraphics::removeMe(){
    int i=0;
    while(i<targetCollection.count()){
        targetCollection.at(i)->removeFeed();
        i=i+1;
    }
    i=0;
    while(i<providerCollection.count()){
        providerCollection.at(i)->removeAllFeed();
        i=i+1;
    }
    pv->removePG(this);
}
