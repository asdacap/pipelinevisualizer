#include "processgraphics.h"
#include "pipetarget.h"
#include "pipeprovider.h"
#include "QBrush"
#include "pvisual.h"

const int Margin=10;

ProcessGraphics::ProcessGraphics(SignalProcessor* theprocessor,QString name, int inputNum, int outputNum,PVisual* pvis){
    thename=name;
    processor=theprocessor;
    in=inputNum;
    on=outputNum;
    setFlag(ItemIsMovable,true);
    setFlag(ItemSendsGeometryChanges,true);
    setBrush(QBrush(Qt::cyan));
    QGraphicsSimpleTextItem* text=new QGraphicsSimpleTextItem(this);
    text->setText(thename);
    text->setPos(20+Margin,0);
    int maxnum=inputNum;
    if(on>maxnum)maxnum=on;
    setRect(0,0,text->boundingRect().width()+40+Margin*2,maxnum*20);

    int i=0;
    while(i<in){
        PipeTarget* targ=new PipeTarget(i,processor,pvis->getSignalTargetCollection());
        targ->setParentItem(this);
        targ->setPos(0,i*20);
        targetlist.append(targ);
        i=i+1;
    }

    i=0;
    while(i<on){
        PipeProvider* targ=new PipeProvider(this,i,pvis->getSignalTargetCollection());
        targ->setParentItem(this);
        targ->setPos(20+text->boundingRect().width()+Margin*2,i*20);
        providerlist.append(targ);
        i=i+1;
    }

}

QString ProcessGraphics::getName(){
    return thename;
}

SignalProcessor* ProcessGraphics::getProcessor(){
    return processor;
}

QVariant ProcessGraphics::itemChange(GraphicsItemChange change, const QVariant &value){
    switch (change) {
     case ItemPositionHasChanged:{
         int i=0;
         while(i<targetlist.count()){
             targetlist.at(i)->realign();
             i=i+1;
         }
         i=0;
         while(i<providerlist.count()){
             providerlist.at(i)->realign();
             i=i+1;
         }
         break;}
         default:
         break;
     };

     return QGraphicsItem::itemChange(change, value);
}
