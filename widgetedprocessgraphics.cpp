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
#include "QInputDialog"

const int Margin=5;

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
ProcessGraphics(theprocessor,name,prov,inputNum,outputNum,doubleinputNum,doubleOutputNum,
        boolInputNum,boolOutputNum,pvis){

    setFlag(ItemIsMovable,true);
    setFlag(ItemSendsGeometryChanges,true);
    setAcceptHoverEvents(true);


    this->wid=wid;
    this->rect=rect;
    setToolTip(getProvider()->getToolTip());
    text=new QGraphicsSimpleTextItem(this);
    text->setText(getName());
    proxy=new GraphicProxyWidgetGraphHack();
    proxy->setParentItem(this);
    proxy->setAcceptHoverEvents(true);
    InitializeUi();

    prevstatus=true;
    reftimer.setInterval(500);
    reftimer.setSingleShot(false);
    QObject::connect(&reftimer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
    reftimer.start();

    removeAction=new QAction("remove",this);
    QObject::connect(removeAction,SIGNAL(triggered()),this,SLOT(removeMe()));
    renameAction=new QAction("rename",this);
    QObject::connect(renameAction,SIGNAL(triggered()),this,SLOT(renameMe()));
}

void WidgetedProcessGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(proxy->contains(proxy->mapFromScene(event->scenePos()))){

    }else{
        ProcessGraphics::mouseMoveEvent(event);
    }
}

void WidgetedProcessGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(proxy->contains(proxy->mapFromScene(event->scenePos()))){
        proxy->grabMouse();
    }else{
        ProcessGraphics::mousePressEvent(event);
    }
}

void WidgetedProcessGraphics::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    if(proxy->contains(proxy->mapFromScene(event->scenePos()))){
       // proxy->ungrabMouse();
        //ungrabMouse();
    }else{
        ProcessGraphics::mouseReleaseEvent(event);
    }
}

void WidgetedProcessGraphics::InitializeUi(){
    int inputNum=getSignalTarget().count();
    int outputNum=getSignalPipeProvider().count();
    int doubleinputNum=getDoublePipeTarget().count();
    int doubleOutputNum=getDoublePipeProvider().count();
    int boolInputNum=getBoolPipeTarget().count();
    int boolOutputNum=getBoolPipeProvider().count();
    int on=getSignalPipeProvider().count();

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
    int wwidth=rect.width();
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

    proxy->setWidget(wid);
    proxy->setGeometry(rect);
    proxy->setPos(signalinputwidth+Margin,boldoubsiginputheight+text->boundingRect().height());


    //CalculateHeight
    int height=0;
    int iheight=inputNum*20;
    int oheight=outputNum*20;
    int theight=text->boundingRect().height()+boldoubsiginputheight+boldoubsigoutputheigt+rect.height();
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

    QList<PipeTarget*> targetlist=getSignalTarget();
    int i=0;
    while(i<targetlist.count()){
        targetlist.at(i)->setPos(0,i*20);
        i=i+1;
    }

    QList<PipeProvider*> providerlist=getSignalPipeProvider();
    i=0;
    while(i<providerlist.count()){
        providerlist.at(i)->setPos(boundingRect().width()-20,i*20);
        i=i+1;
    }

    targetlist=getDoublePipeTarget();
    i=0;
    while(i<targetlist.count()){
        targetlist.at(i)->setPos(signalinputwidth+Margin+(i*20),0);
        i=i+1;
    }

    providerlist=getDoublePipeProvider();
    i=0;
    while(i<providerlist.count()){
        providerlist.at(i)->setPos(signalinputwidth+Margin+(i*20),boundingRect().height()-20);
        i=i+1;
    }

    targetlist=getBoolPipeTarget();
    i=0;
    while(i<targetlist.count()){
        targetlist.at(i)->setPos(boundingRect().width()-(signaloutputwidth+20+Margin+(i*20)),0);
        i=i+1;
    }

    providerlist=getBoolPipeProvider();
    i=0;
    while(i<providerlist.count()){
        providerlist.at(i)->setPos(boundingRect().width()-(signaloutputwidth+20+Margin+(i*20)),boundingRect().height()-20);
        i=i+1;
    }
}

QRectF WidgetedProcessGraphics::boundingRect() const{
    return QRectF(0,0,thewidth,theheight);
}

void WidgetedProcessGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(prevstatus){
        painter->setBrush(QBrush(option->palette.background()));
    }else{
        painter->setBrush(QBrush(Qt::magenta));
    }
    painter->drawRect(boundingRect());
}

void WidgetedProcessGraphics::renameMe(){
    bool ok;
    QString cand=getName();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         if(pv->isExistPGName(text))return;
         pgName=text;
         this->text->setText(getName());
         InitializeUi();
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return;
     }

}

QVariant WidgetedProcessGraphics::itemChange(GraphicsItemChange change, const QVariant &value){
    switch (change) {
     case ItemPositionHasChanged:{
         int i=0;
         while(i<getTarget().count()){
             getTarget().at(i)->realign();
             i=i+1;
         }
         i=0;
         while(i<getPipeProvider().count()){
             getPipeProvider().at(i)->realign();
             i=i+1;
         }
         break;}
         default:
         break;
     };

     return QGraphicsItem::itemChange(change, value);
}

void WidgetedProcessGraphics::timerElapsed(){
    if(prevstatus!=getProcessor()->isStarted()){
        prevstatus=getProcessor()->isStarted();
        if(prevstatus){

            update();
        }else{

            update();
        }
    }
}

void WidgetedProcessGraphics::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
    QList<QAction*> actionlist;
    actionlist.append(removeAction);
    actionlist.append(renameAction);
    QMenu::exec(actionlist,event->screenPos(),0);
}

QWidget* WidgetedProcessGraphics::getWidget(){
    return proxy->widget();
}

void WidgetedProcessGraphics::removeMe(){
    ProcessGraphics::removeMe();
}
