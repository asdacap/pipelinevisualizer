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

#include "processgraphics.h"
#include "signalpipetarget.h"
#include "signalpipeprovider.h"
#include "doublepipetarget.h"
#include "doublepipeprovider.h"
#include "booleanpipetarget.h"
#include "booleanpipeprovider.h"
#include "pvisual.h"
#include "iostream"

ProcessGraphics::ProcessGraphics(SignalProcessor *sp, QString name, PipeProcessGraphicsProvider *prov,
                                 int sinput, int soutput, int dinput, int doutput, int binput, int boutput,
                                 PVisual* pvi){
    processor=sp;
    pgName=name;
    provider=prov;
    pv=pvi;
    PVisual* pvis=pv;
    setFlag(ItemIsMovable,true);
    setFlag(ItemIsSelectable,true);

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

void ProcessGraphics::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*){

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

void ProcessGraphics::realign(){
    int i=0;
    while(i<targetCollection.count()){
        targetCollection.at(i)->realign();
        i=i+1;
    }
    i=0;
    while(i<providerCollection.count()){
        providerCollection.at(i)->realign();
        i=i+1;
    }
}

QVariant ProcessGraphics::itemChange(GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}
