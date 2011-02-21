#include "widgetedprocessgraphics.h"
#include "processgraphics.h"
#include "pipetarget.h"
#include "pipeprovider.h"
#include "QBrush"
#include "pvisual.h"
#include "signalpipeprovider.h"
#include "signalpipetarget.h"
#include "doublepipeprovider.h"
#include "doublepipetarget.h"
#include "booleanpipetarget.h"
#include "booleanpipeprovider.h"
#include "iostream"
#include "QMenu"
#include "QGraphicsSceneContextMenuEvent"
#include "QGraphicsProxyWidget"
#include <iostream>

const int Margin=10;

WidgetedProcessGraphics::WidgetedProcessGraphics(SignalProcessor* theprocessor,
                                 QString name,
                                 int inputNum,
                                 int outputNum,
                                 int doubleinputNum,
                                 int doubleOutputNum,
                                 int boolInputNum,
                                 int boolOutputNum,
                                 PVisual* pvis,
                                 PipeProcessGraphicsProvider* prov,
                                 QWidget* wid,
                                 QRectF rect):
ProcessGraphics(){
    thename=name;
    processor=theprocessor;
    pv=pvis;
    in=inputNum;
    on=outputNum;
    provider=prov;
    setFlag(ItemIsMovable,true);
    setFlag(ItemSendsGeometryChanges,true);
    setAcceptHoverEvents(true);

    InitializeUi(inputNum,outputNum,doubleinputNum,doubleOutputNum,boolInputNum,boolOutputNum,wid,rect);

    prevstatus=true;
    reftimer.setInterval(500);
    reftimer.setSingleShot(false);
    QObject::connect(&reftimer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
    reftimer.start();

    removeAction=new QAction("remove",this);
    QObject::connect(removeAction,SIGNAL(triggered()),this,SLOT(removeMe()));
}

PipeProcessGraphicsProvider* WidgetedProcessGraphics::getProvider(){
    return provider;
}

QList<PipeTarget*> WidgetedProcessGraphics::getTarget(){
    return targetlist;
}

QList<PipeProvider*> WidgetedProcessGraphics::getPipeProvider(){
    return providerlist;
}

void WidgetedProcessGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(theproxwid->contains(theproxwid->mapFromScene(event->scenePos()))){

    }else{
        ProcessGraphics::mouseMoveEvent(event);
    }
}

void WidgetedProcessGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(theproxwid->contains(theproxwid->mapFromScene(event->scenePos()))){
        theproxwid->grabMouse();
    }else{
        ProcessGraphics::mousePressEvent(event);
    }
}

void WidgetedProcessGraphics::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    if(theproxwid->contains(theproxwid->mapFromScene(event->scenePos()))){
       // theproxwid->ungrabMouse();
        //ungrabMouse();
    }else{
        ProcessGraphics::mouseReleaseEvent(event);
    }
}

void WidgetedProcessGraphics::InitializeUi(int sInputNum, int sOutputNum, int dInputNum, int dOutputNum, int bInputNum, int bOutputNum,QWidget* wid,QRectF rec){
    setToolTip(getProvider()->getToolTip());

    int inputNum=sInputNum;
    int outputNum=sOutputNum;
    int doubleinputNum=dInputNum;
    int doubleOutputNum=dOutputNum;
    int boolInputNum=bInputNum;
    int boolOutputNum=bOutputNum;
    PVisual* pvis=pv;

    QGraphicsSimpleTextItem* text=new QGraphicsSimpleTextItem(this);
    text->setText(thename);
    int maxnum=inputNum;
    if(on>maxnum)maxnum=on;

    //Posutil.
    int signalinputwidth=0;
    if(inputNum>0)signalinputwidth=20;
    int signaloutputwidth=0;
    if(outputNum>0)signaloutputwidth=20;
    int boldoubsiginputheight=0;
    if(doubleinputNum+boolInputNum>0){
        boldoubsiginputheight=20+Margin;
    }else{
        boldoubsiginputheight=0;
    }
    int boldoubsigoutputheigt=0;
    if(doubleOutputNum+boolOutputNum>0){
        boldoubsigoutputheigt=20+Margin;
    }

    //Calculate width
    int width=0;
    int twidth=text->boundingRect().width();
    int iwidth=(boolInputNum+doubleinputNum)*20;
    int owidth=(boolOutputNum+doubleOutputNum)*20;
    int wwidth=rec.width();
    if(twidth>width)width=twidth;
    if(iwidth>width)width=iwidth;
    if(owidth>width)width=owidth;
    if(wwidth>width)width=wwidth;

    if(inputNum>0)width=width+20;
    if(outputNum>0)width=width+20;
    width=width+(Margin*2);

    //Text pos
    text->setPos(signalinputwidth+Margin,boldoubsiginputheight);

    //Put Widget
    QGraphicsProxyWidget* proxy=new GraphicProxyWidgetGraphHack();
    proxy->setParentItem(this);
    theproxwid=proxy;
    proxy->setWidget(wid);
    proxy->setGeometry(rec);
    proxy->setPos(signalinputwidth+Margin,boldoubsiginputheight+text->boundingRect().height());
    proxy->setAcceptHoverEvents(true);

    //CalculateHeight
    int height=0;
    int iheight=inputNum*20;
    int oheight=outputNum*20;
    int theight=text->boundingRect().height()+boldoubsiginputheight+boldoubsigoutputheigt+rec.height();
    if(iheight>oheight){
        height=iheight;
    }else{
        height=oheight;
    }
    if(theight>height){
        height=theight;
    }

    thewidth=width;
    theheight=height;

    int i=0;
    while(i<in){
        SignalPipeTarget* targ=new SignalPipeTarget(i,processor,pvis->getSignalTargetCollection());
        targ->setToolTip(getProvider()->getTargetToolTip(i));
        targ->setParentItem(this);
        targ->setPos(0,i*20);
        targetlist.append(targ);
        i=i+1;
    }

    i=0;
    while(i<on){
        SignalPipeProvider* targ=new SignalPipeProvider(this,i,pvis->getSignalTargetCollection());
        targ->setToolTip(getProvider()->getProviderToolTip(i));
        targ->setParentItem(this);
        targ->setPos(boundingRect().width()-20,i*20);
        providerlist.append(targ);
        i=i+1;
    }

    i=0;
    while(i<doubleinputNum){
        DoublePipeTarget* dtarg=new DoublePipeTarget(i,processor,pvis->getDoubleTargetCollection());
        dtarg->setToolTip(getProvider()->getTargetToolTip(i+in));
        dtarg->setParentItem(this);
        dtarg->setPos(signalinputwidth+Margin+(i*20),0);
        targetlist.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<doubleOutputNum){
        DoublePipeProvider* dtarg=new DoublePipeProvider(this,i,pvis->getDoubleTargetCollection());
        dtarg->setToolTip(getProvider()->getProviderToolTip(i+on));
        dtarg->setParentItem(this);
        dtarg->setPos(signalinputwidth+Margin+(i*20),boundingRect().height()-20);
        providerlist.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<boolInputNum){
        PipeTarget* dtarg=new BooleanPipeTarget(i,processor,pvis->getBoolTargetCollection());
        dtarg->setToolTip(getProvider()->getTargetToolTip(i+in+doubleinputNum));
        dtarg->setParentItem(this);
        dtarg->setPos(boundingRect().width()-(signaloutputwidth+20+Margin+(i*20)),0);
        targetlist.append(dtarg);
        i=i+1;
    }

    i=0;
    while(i<boolOutputNum){
        BooleanPipeProvider* dtarg=new BooleanPipeProvider(this,i,pvis->getBoolTargetCollection());
        dtarg->setToolTip(getProvider()->getProviderToolTip(i+on+doubleOutputNum));
        dtarg->setParentItem(this);
        dtarg->setPos(boundingRect().width()-(signaloutputwidth+20+Margin+(i*20)),boundingRect().height()-20);
        providerlist.append(dtarg);
        i=i+1;
    }
}

QRectF WidgetedProcessGraphics::boundingRect() const{
    return QRectF(0,0,thewidth,theheight);
}

void WidgetedProcessGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(prevstatus){
        painter->setBrush(QBrush(Qt::cyan));
    }else{
        painter->setBrush(QBrush(Qt::magenta));
    }
    painter->drawRect(boundingRect());
}

QString WidgetedProcessGraphics::getName(){
    return thename;
}

SignalProcessor* WidgetedProcessGraphics::getProcessor(){
    return processor;
}

QVariant WidgetedProcessGraphics::itemChange(GraphicsItemChange change, const QVariant &value){
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

void WidgetedProcessGraphics::timerElapsed(){
    if(prevstatus!=processor->isStarted()){
        prevstatus=processor->isStarted();
        if(prevstatus){

            update();
        }else{

            update();
        }
    }
}

void WidgetedProcessGraphics::removeMe(){
    int i=0;
    while(i<targetlist.count()){
        targetlist.at(i)->removeFeed();
        i=i+1;
    }
    i=0;
    while(i<providerlist.count()){
        providerlist.at(i)->removeAllFeed();
        i=i+1;
    }
    pv->removePG(this);
}

void WidgetedProcessGraphics::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
    QList<QAction*> actionlist;
    actionlist.append(removeAction);

    QMenu::exec(actionlist,event->screenPos(),0);
}

QWidget* WidgetedProcessGraphics::getWidget(){
    return theproxwid->widget();
}
