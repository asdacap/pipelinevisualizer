#include "mainprogram.h"
#include "pipefeed.h"
#include "pipeprovider.h"
#include "processgraphics.h"
#include "signalprocessor.h"
#include "QComboBox"
#include "QPushButton"
#include "soundfeeder.h"
#include "soundsink.h"
#include "QFileDialog"
#include "providerplugininterface.h"
#include <iostream>

MainProgram::MainProgram(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget* cwid=new QWidget(this);
    setCentralWidget(cwid);

    scene=new QGraphicsScene(this);
    scene->setItemIndexMethod(scene->NoIndex);
    view=new QGraphicsView(centralWidget());
    view->setScene(scene);
    view->setDragMode(view->ScrollHandDrag);

    QToolBar* mainToolBar=new QToolBar("Main Toolbar");
    addToolBar(mainToolBar);
    QAction* curAt=mainToolBar->addAction("StartAll");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(startButton()));
    curAt=mainToolBar->addAction("StopAll");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(stopButton()));
    curAt=mainToolBar->addAction("Clear");
    QObject::connect(curAt,SIGNAL(triggered()),this,SLOT(removeAllButton()));
    zoomInAction=mainToolBar->addAction("zoomIn");
    QObject::connect(zoomInAction,SIGNAL(triggered()),this,SLOT(zoomIn()));
    zoomOutAction=mainToolBar->addAction("zoomOut");
    QObject::connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(zoomOut()));

    loadAction=new QAction("Load",this);
    QObject::connect(loadAction,SIGNAL(triggered()),this,SLOT(loadButton()));
    saveAction=new QAction("Save",this);
    QObject::connect(saveAction,SIGNAL(triggered()),this,SLOT(saveButton()));
    loadPluginAction=new QAction("LoadPlugin",this);
    QObject::connect(loadPluginAction,SIGNAL(triggered()),this,SLOT(loadPlugin()));

    QMenu* filemenu=menuBar()->addMenu("File");
    menuBar()->addAction(loadPluginAction);
    filemenu->addAction(loadAction);
    filemenu->addAction(saveAction);

    addSPwidget=new QWidget();
    QDockWidget* dock=new QDockWidget("Add signal processor");
    dock->setFeatures(dock->DockWidgetMovable|dock->DockWidgetFloatable);
    QScrollArea* area=new QScrollArea();
    area->setWidget(addSPwidget);
    addSPwidget->setMinimumSize(300,600);
    addSPwidget->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    dock->setWidget(area);
    spwidgetLayout=new QBoxLayout(QBoxLayout::BottomToTop,this);
    spwidgetLayout->setSpacing(1);
    addSPwidget->setLayout(spwidgetLayout);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    setCentralWidget(view);

    sigcol=new TargetCollection();
    doubcol=new TargetCollection();
    boolcol=new TargetCollection();

    InitializeProvider();

    curscale=1;

}

void MainProgram::removeAllButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->removeMe();
    }
}

void MainProgram::startButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->getProcessor()->start();
        i=i+1;
    }
}

void MainProgram::stopButton(){
    int i=0;
    while(i<pgraphics_list.count()){
        pgraphics_list.at(i)->getProcessor()->stop();
        i=i+1;
    }
}

void MainProgram::InitializeProvider(){
    addProvider(new SoundSinkProvider(this));
    addProvider(new SoundFeederProvider(this));
}

void MainProgram::addProvider(PipeProcessGraphicsProvider *prov){
    if(isExistProviderName(prov->getName()))return;
    provider_list.append(prov);
    AddSPButton* newbu=new AddSPButton(prov->getName(),this);
    newbu->setParent(addSPwidget);
    spwidgetLayout->addWidget(newbu);
}

bool MainProgram::isExistProviderName(QString name){
    int i=0;
    while(i<provider_list.count()){
        if(provider_list.at(i)->getName()==name)return true;
        i=i+1;
    }
    return false;
}

void MainProgram::addPG(ProcessGraphics* newpg){
    if(newpg==0){
        std::cout<<"Numll pg given"<<std::endl;
        return ;
    }
    if(isExistPGName(newpg->getName()))return ;
    scene->addItem(newpg);
    pgraphics_list.append(newpg);
    newpg->setPos(view->mapToScene(view->width()/2-newpg->boundingRect().width()/2
                                   ,view->height()/2-newpg->boundingRect().height()/2));
}

void MainProgram::addPG(QString providername){
    foreach (PipeProcessGraphicsProvider* prov,provider_list) {
        if(prov->getName()==providername){
            addPG(prov->newInstance());
        }
    }
}

void MainProgram::removePG(ProcessGraphics *pg){
    scene->removeItem(pg);
    pgraphics_list.removeAll(pg);
    pg->setParent(0);
    delete pg;
}

bool MainProgram::isExistPGName(QString name){
    int i=0;
    while(i<pgraphics_list.count()){
        if(pgraphics_list.at(i)->getName()==name)return true;
        i=i+1;
    }
    return false;
}

MainProgram::~MainProgram()
{
}

TargetCollection* MainProgram::getSignalTargetCollection(){
    return sigcol;
}

TargetCollection* MainProgram::getDoubleTargetCollection(){
    return doubcol;
}

TargetCollection* MainProgram::getBoolTargetCollection(){
    return boolcol;
}

TiXmlElement getPGElement(ProcessGraphics* pg){
    TiXmlElement thenewel(pg->getProvider()->getName().toAscii());
    QMap<QString,QString> setting=pg->getProvider()->getSettings(pg);
    setting["xPos"]=QVariant(pg->pos().x()).toString();
    setting["yPos"]=QVariant(pg->pos().y()).toString();
    QList<QString> keys=setting.keys();
    int i=0;
    while(i<keys.count()){
        thenewel.SetAttribute(keys.at(i).toAscii().data(),setting[keys.at(i)].toAscii().data());
        i=i+1;
    }

    return thenewel;
}

void putSignalConnection(TiXmlElement* el,ProcessGraphics* pg){
    QList<PipeTarget*> targetlist=pg->getSignalTarget();
    int i=0;
    while(i<targetlist.count()){
        PipeTarget* target=targetlist.at(i);
        if(!target->isAvailable()){
            QString targetSPName=pg->getName();
            int targetid=target->getID();
            QString providerSPName=target->getFeed()->provider->getProcessGraphics()->getName();
            int providerid=target->getFeed()->provider->getId();
            TiXmlElement* connectionEl=new TiXmlElement("connection");
            connectionEl->SetAttribute("target",targetSPName.toAscii().data());
            connectionEl->SetAttribute("targetID",QVariant(targetid).toString().toAscii().data());
            connectionEl->SetAttribute("source",providerSPName.toAscii().data());
            connectionEl->SetAttribute("sourceID",QVariant(providerid).toString().toAscii().data());
            el->LinkEndChild(connectionEl);
        }
        i=i+1;
    }
}

void putDoubleConnection(TiXmlElement* el,ProcessGraphics* pg){
    QList<PipeTarget*> targetlist=pg->getDoublePipeTarget();
    int i=0;
    while(i<targetlist.count()){
        PipeTarget* target=targetlist.at(i);
        if(!target->isAvailable()){
            QString targetSPName=pg->getName();
            int targetid=target->getID();
            QString providerSPName=target->getFeed()->provider->getProcessGraphics()->getName();
            int providerid=target->getFeed()->provider->getId();
            TiXmlElement* connectionEl=new TiXmlElement("connection");
            connectionEl->SetAttribute("target",targetSPName.toAscii().data());
            connectionEl->SetAttribute("targetID",QVariant(targetid).toString().toAscii().data());
            connectionEl->SetAttribute("source",providerSPName.toAscii().data());
            connectionEl->SetAttribute("sourceID",QVariant(providerid).toString().toAscii().data());
            el->LinkEndChild(connectionEl);
        }
        i=i+1;
    }
}

void putBoolConnection(TiXmlElement* el,ProcessGraphics* pg){
    QList<PipeTarget*> targetlist=pg->getBoolPipeTarget();
    int i=0;
    while(i<targetlist.count()){
        PipeTarget* target=targetlist.at(i);
        if(!target->isAvailable()){
            QString targetSPName=pg->getName();
            int targetid=target->getID();
            QString providerSPName=target->getFeed()->provider->getProcessGraphics()->getName();
            int providerid=target->getFeed()->provider->getId();
            TiXmlElement* connectionEl=new TiXmlElement("connection");
            connectionEl->SetAttribute("target",targetSPName.toAscii().data());
            connectionEl->SetAttribute("targetID",QVariant(targetid).toString().toAscii().data());
            connectionEl->SetAttribute("source",providerSPName.toAscii().data());
            connectionEl->SetAttribute("sourceID",QVariant(providerid).toString().toAscii().data());
            el->LinkEndChild(connectionEl);
        }
        i=i+1;
    }
}


void MainProgram::saveButton(){
    TiXmlDocument mydoc("MainProgram");
    TiXmlElement PGElement("ProcessGraphics");


    int i=0;
    while(i<pgraphics_list.count()){
        PGElement.InsertEndChild(getPGElement(pgraphics_list.at(i)));
        i=i+1;
    }

    mydoc.InsertEndChild(PGElement);
    TiXmlElement ConnectionElement("SignalConnection");
    i=0;
    while(i<pgraphics_list.count()){
        putSignalConnection(&ConnectionElement,pgraphics_list.at(i));
        i=i+1;
    }
    mydoc.InsertEndChild(ConnectionElement);
    ConnectionElement=TiXmlElement("DoubleConnection");
    i=0;
    while(i<pgraphics_list.count()){
        putDoubleConnection(&ConnectionElement,pgraphics_list.at(i));
        i=i+1;
    }
    mydoc.InsertEndChild(ConnectionElement);
    ConnectionElement=TiXmlElement("BoolConnection");
    i=0;
    while(i<pgraphics_list.count()){
        putBoolConnection(&ConnectionElement,pgraphics_list.at(i));
        i=i+1;
    }
    mydoc.InsertEndChild(ConnectionElement);


    QString filename=QFileDialog::getSaveFileName();
    if(filename.isEmpty())return;
    mydoc.SaveFile(filename.toAscii());
}

void MainProgram::loadPg(TiXmlElement *elm){
    QString name(elm->Value());
    QMap<QString,QString> setting;
    TiXmlAttribute* atrr=elm->FirstAttribute();
    while(atrr!=NULL){
        setting[QString(atrr->Name())]=QString(atrr->Value());
        atrr=atrr->Next();
    }
    int i=0;
    while(i<provider_list.count()){
        if(provider_list.at(i)->getName()==name){
            ProcessGraphics* thenewpg=provider_list.at(i)->newInstance(setting);
            if(thenewpg!=0){
                int xpos=(int)QVariant(setting["xPos"]).toDouble();
                int ypos=(int)QVariant(setting["yPos"]).toDouble();
                addPG(thenewpg);
                thenewpg->setPos(xpos,ypos);
            }
        }
        i=i+1;
    }

}

ProcessGraphics* MainProgram::getProcessGraphics(QString name){
    int i=0;
    while(i<pgraphics_list.count()){
        if(pgraphics_list.at(i)->getName()==name)return pgraphics_list.at(i);
        i=i+1;
    }
    return 0;
}

void MainProgram::loadSignalConnection(TiXmlElement *elm){
    TiXmlElement* curelem=elm;

    QString target(curelem->Attribute("target"));
    QString targetId(curelem->Attribute("targetID"));
    QString source(curelem->Attribute("source"));
    QString sourceId(curelem->Attribute("sourceID"));
    ProcessGraphics* targetPG=getProcessGraphics(target);
    ProcessGraphics* sourcePG=getProcessGraphics(source);
    int targetPGID=QVariant(targetId).toInt();
    int sourcePGID=QVariant(sourceId).toInt();
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getSignalPipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getSignalTarget()[targetPGID]);
    }

}

void MainProgram::loadDoubleConnection(TiXmlElement *elm){
    TiXmlElement* curelem=elm;

    QString target(curelem->Attribute("target"));
    QString targetId(curelem->Attribute("targetID"));
    QString source(curelem->Attribute("source"));
    QString sourceId(curelem->Attribute("sourceID"));
    ProcessGraphics* targetPG=getProcessGraphics(target);
    ProcessGraphics* sourcePG=getProcessGraphics(source);
    int targetPGID=QVariant(targetId).toInt();
    int sourcePGID=QVariant(sourceId).toInt();
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getDoublePipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getDoublePipeTarget()[targetPGID]);
    }

}
void MainProgram::loadBoolConnection(TiXmlElement *elm){
    TiXmlElement* curelem=elm;

    QString target(curelem->Attribute("target"));
    QString targetId(curelem->Attribute("targetID"));
    QString source(curelem->Attribute("source"));
    QString sourceId(curelem->Attribute("sourceID"));
    ProcessGraphics* targetPG=getProcessGraphics(target);
    ProcessGraphics* sourcePG=getProcessGraphics(source);
    int targetPGID=QVariant(targetId).toInt();
    int sourcePGID=QVariant(sourceId).toInt();
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getBoolPipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getBoolPipeTarget()[targetPGID]);
    }

}

void MainProgram::loadButton(){
    QString path=QFileDialog::getOpenFileName();
    TiXmlDocument mydoc;
    if(!mydoc.LoadFile(path.toAscii())){
        std::cout<<"Unable to load xml"<<std::endl;
        std::cout<<mydoc.ErrorDesc()<<std::endl;
        return;
    }
    removeAllButton();
    TiXmlElement* pgelement=(TiXmlElement*)mydoc.FirstChildElement("ProcessGraphics");
    TiXmlElement* currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadPg(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc.FirstChildElement("SignalConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadSignalConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc.FirstChildElement("DoubleConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadDoubleConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc.FirstChildElement("BoolConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadBoolConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
}

void MainProgram::zoomIn(){
    view->scale(1.2,1.2);
}

void MainProgram::zoomOut(){
    view->scale(0.8,0.8);
}

void MainProgram::loadPlugin(){
    std::cout<<"Load plugin"<<std::endl;
    QString filepath=QFileDialog::getOpenFileName();
    if(!filepath.isEmpty()){
        QPluginLoader* loader=new QPluginLoader(filepath,this);
        if(!loader->load()){
            std::cout<<"Load plugin failed"<<std::endl;
            std::cout<<loader->errorString().toStdString()<<std::endl;
            return ;
        }
        ProviderPluginInterface* plugin=qobject_cast<ProviderPluginInterface*>(loader->instance());
        if(plugin){
            QList<PipeProcessGraphicsProvider*> providerlist=plugin->getProviders(this);
            foreach (PipeProcessGraphicsProvider* provider,providerlist) {
                addProvider(provider);
            }
        }else{
            std::cout<<"Plugin empty"<<std::endl;
        }
    }
}

AddSPButton::AddSPButton(QString provstring, MainProgram *pv):QPushButton(provstring){
    PV=pv;
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(AddProv()));
    setFlat(true);
}

void AddSPButton::AddProv(){
    PV->addPG(text());

}

