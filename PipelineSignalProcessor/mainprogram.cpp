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

#include "mainprogram.h"
#include "pipefeed.h"
#include "pipeprovider.h"
#include "processgraphics.h"
#include "signalprocessor.h"
#include "QComboBox"
#include "QPushButton"
#include "QFileDialog"
#include "providerplugininterface.h"
#include <QToolBar>
#include <QMenuBar>
#include <QDockWidget>
#include <iostream>
#include <QPluginLoader>
#include <QTextStream>
#include <QApplication>
#include <stringlisteditor.h>

MainProgram::MainProgram(QWidget *parent) :
    QMainWindow(parent)
{
    pvis=new PVisual();
    pvis->setParent(this);
    QWidget* cwid=pvis;
    setCentralWidget(cwid);

    loadAction=new QAction("Load",this);
    QObject::connect(loadAction,SIGNAL(triggered()),this,SLOT(loadButton()));
    saveAction=new QAction("Save",this);
    QObject::connect(saveAction,SIGNAL(triggered()),this,SLOT(saveButton()));
    loadPluginAction=new QAction("LoadPlugin",this);
    QObject::connect(loadPluginAction,SIGNAL(triggered()),this,SLOT(loadPlugin()));
    pluginListAction=new QAction("Configure Default Plugins",this);
    QObject::connect(pluginListAction,SIGNAL(triggered()),this,SLOT(openPluginListEditor()));

    QMenu* filemenu=menuBar()->addMenu("File");
    menuBar()->addAction(loadPluginAction);
    menuBar()->addAction(pluginListAction);
    filemenu->addAction(loadAction);
    filemenu->addAction(saveAction);

    addSPwidget=new QListWidget();
    QDockWidget* dock=new QDockWidget("Add signal processor");
    dock->setFeatures(dock->DockWidgetMovable|dock->DockWidgetFloatable);
    dock->setWidget(addSPwidget);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    connect(addSPwidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),SLOT(listDoubleClicked(QListWidgetItem*)));

    InitializeProvider();

}


void MainProgram::InitializeProvider(){
    loadDefaultPlugin();
}

void MainProgram::addProvider(PipeProcessGraphicsProvider *prov){
    if(isExistProviderName(prov->getName()))return;
    provider_list.append(prov);
    addSPwidget->addItem(prov->getName());
}

bool MainProgram::isExistProviderName(QString name){
    int i=0;
    while(i<provider_list.count()){
        if(provider_list.at(i)->getName()==name)return true;
        i=i+1;
    }
    return false;
}


void MainProgram::addPG(QString providername){
    foreach (PipeProcessGraphicsProvider* prov,provider_list) {
        if(prov->getName()==providername){
            pvis->addPG(prov->newInstance());
        }
    }
}

MainProgram::~MainProgram()
{
}

void MainProgram::loadDefaultPlugin(){
    QFile plistfile("plugins.lst");
    plistfile.open(QIODevice::ReadOnly);
    QList<QString> pathlist;
    QTextStream helperinstance(&plistfile);
    while(!helperinstance.atEnd()){
        pathlist.append(helperinstance.readLine());
    }
    foreach (QString filepath, pathlist) {
        loadPlugin(filepath);
    }
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
    QList<ProcessGraphics*> pgraphics_list=pvis->getProcessGraphics();

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
                pvis->addPG(thenewpg);
                thenewpg->setPos(xpos,ypos);
            }
        }
        i=i+1;
    }

}


void MainProgram::loadSignalConnection(TiXmlElement *elm){
    TiXmlElement* curelem=elm;

    QString target(curelem->Attribute("target"));
    QString targetId(curelem->Attribute("targetID"));
    QString source(curelem->Attribute("source"));
    QString sourceId(curelem->Attribute("sourceID"));
    ProcessGraphics* targetPG=pvis->getProcessGraphics(target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(source);
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
    ProcessGraphics* targetPG=pvis->getProcessGraphics(target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(source);
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
    ProcessGraphics* targetPG=pvis->getProcessGraphics(target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(source);
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
    pvis->removeAllButton();
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

void MainProgram::loadPlugin(){
    std::cout<<"Load plugin"<<std::endl;
    QString filepath=QFileDialog::getOpenFileName();
    loadPlugin(filepath);
}

void MainProgram::loadPlugin(QString filepath){
    if(!filepath.isEmpty()){
        QString abspath=QDir(QApplication::applicationDirPath()).absoluteFilePath(filepath);
        QPluginLoader* loader=new QPluginLoader(abspath,this);
        if(!loader->load()){
            std::cout<<"Load plugin failed"<<std::endl;
            std::cout<<loader->errorString().toStdString()<<std::endl;
            return ;
        }
        ProviderPluginInterface* plugin=qobject_cast<ProviderPluginInterface*>(loader->instance());
        if(plugin){
            QList<PipeProcessGraphicsProvider*> providerlist=plugin->getProviders(pvis);
            foreach (PipeProcessGraphicsProvider* provider,providerlist) {
                addProvider(provider);
            }
        }else{
            std::cout<<"Plugin empty"<<std::endl;
        }
    }
}

void MainProgram::openPluginListEditor(){
    QList<QString> currentPlugin;
    QString path="plugins.lst";
    QString filepath=path;
    QFile thefile(path);
    thefile.open(QIODevice::ReadOnly);
    QTextStream reader(&thefile);
    while(!reader.atEnd()){
        currentPlugin.append(reader.readLine());
    }
    thefile.close();
    StringlistEditor theditor(currentPlugin,this);
    if(theditor.exec()==theditor.Accepted){
        thefile.open(QIODevice::WriteOnly);
        QList<QString> newstring=theditor.currentList();
        QTextStream writer(&thefile);
        foreach(QString var,newstring){
            writer<<var;
            writer<<"\n";
        }
        thefile.close();
    }
}

void MainProgram::listDoubleClicked(QListWidgetItem *theitem){
    QString thename=theitem->text();
    addPG(thename);
}
