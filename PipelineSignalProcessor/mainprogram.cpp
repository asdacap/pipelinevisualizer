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
#include <templateproxy.h>
#include <QTableView>
#include <templateprocessor.h>
#include <QSplitter>

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
    QAction* loadTemplateAction=new QAction("Load Template",this);
    this->connect(loadTemplateAction,SIGNAL(triggered()),SLOT(loadTemplate()));
    QAction* loadTemplateSettingAction=new QAction("Configure default Templates",this);
    this->connect(loadTemplateSettingAction,SIGNAL(triggered()),SLOT(openTemplateListEditor()));


    QMenu* filemenu=menuBar()->addMenu("File");
    filemenu->addAction(loadAction);
    filemenu->addAction(saveAction);

    QMenu* toolmenu=menuBar()->addMenu("Tools");
    toolmenu->addAction(loadPluginAction);
    toolmenu->addAction(pluginListAction);
    toolmenu->addAction(loadTemplateAction);
    toolmenu->addAction(loadTemplateSettingAction);


    providerlistmodel=new SPProviderListModel();
    addSPwidget=new QTreeView();
    addSPwidget->setModel(providerlistmodel);
    addSPwidget->setSortingEnabled(true);

    QWidget* interdocwidget=new QWidget();
    QVBoxLayout* thelayout=new QVBoxLayout();
    QLineEdit* alinedit=new QLineEdit();
    interdocwidget->setLayout(thelayout);
    thelayout->addWidget(alinedit);
    thelayout->addWidget(addSPwidget);

    QTableView* propertytableview=new QTableView();
    thepropertymodel=new ProccessGraphicsPropertyModel();
    propertytableview->setModel(thepropertymodel);

    connect(alinedit,SIGNAL(textChanged(QString)),providerlistmodel,SLOT(filterWithString(QString)));

    QSplitter* docksplitter=new QSplitter(Qt::Vertical);
    docksplitter->addWidget(interdocwidget);
    docksplitter->addWidget(propertytableview);
    QDockWidget* dock=new QDockWidget("Add signal processor");
    dock->setFeatures(dock->DockWidgetMovable|dock->DockWidgetFloatable);
    dock->setWidget(docksplitter);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    connect(addSPwidget,SIGNAL(doubleClicked(QModelIndex)),SLOT(listDoubleClicked(QModelIndex)));

    connect(pvis,SIGNAL(PGSelected(ProcessGraphics*)),SLOT(PGSelected(ProcessGraphics*)));
    connect(thepropertymodel,SIGNAL(PropertySuggested(QMap<QString,QString>)),SLOT(PropertyChangeSuggested(QMap<QString,QString>)));

    InitializeProvider();

}


void MainProgram::InitializeProvider(){
    loadDefaultPlugin();
    addProvider(new TemplateProxyProvider(pvis));
    loadDefaultTemplate();
}

void MainProgram::addProvider(PipeProcessGraphicsProvider *prov){
    if(prov==0){
        std::cout<<"Warning: Empty provider given"<<std::endl;
        return;
    }
    if(isExistProviderName(prov->getName()))return;
    provider_list.append(prov);
    providerlistmodel->addProvider(prov);
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

void MainProgram::loadDefaultTemplate(){
    QFile plistfile("templates.lst");
    plistfile.open(QIODevice::ReadOnly);
    QList<QString> pathlist;
    QTextStream helperinstance(&plistfile);
    while(!helperinstance.atEnd()){
        pathlist.append(helperinstance.readLine());
    }
    foreach (QString filepath, pathlist) {
        loadTemplate(filepath);
    }
}

void MainProgram::loadTemplate(QString path){
    TiXmlDocument mydoc;
    if(!mydoc.LoadFile(path.toAscii())){
        std::cout<<"Unable to load xml"<<std::endl;
        std::cout<<mydoc.ErrorDesc()<<std::endl;
        return;
    }
    PipelineProfile* theprofile=new PipelineProfile(&mydoc);
    QFileInfo theinfo(path);
    TemplateProcessorProvider* theprovider=new TemplateProcessorProvider(theinfo.baseName(),theprofile,&provider_list,pvis);
    addProvider(theprovider);
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


    QString filename=QFileDialog::getSaveFileName(this,"Save pipeline","","PipelineVisualizer file(*.pvl)");
    if(filename.isEmpty())return;
    mydoc.SaveFile(filename.toAscii());
}


void MainProgram::loadButton(){
    QString path=QFileDialog::getOpenFileName(this,"Open project file","","PipelineVisualizer file (*.pvl)");
    TiXmlDocument mydoc;
    if(!mydoc.LoadFile(path.toAscii())){
        std::cout<<"Unable to load xml"<<std::endl;
        std::cout<<mydoc.ErrorDesc()<<std::endl;
        return;
    }
    pvis->removeAllButton();
    PipelineProfile theprofile(&mydoc);
    theprofile.InitializeIt(pvis,provider_list);
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
            std::cout<<"Load plugin failed for plugin: "<<filepath.toStdString()<<std::endl;
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

void MainProgram::openTemplateListEditor(){
    QList<QString> currentPlugin;
    QString path="templates.lst";
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

void MainProgram::listDoubleClicked(QModelIndex theindex){
    addPG(providerlistmodel->data(theindex,Qt::DisplayRole).toString());
}

void MainProgram::loadTemplate(){

    QString path=QFileDialog::getOpenFileName(this,"Open template/project file","","PipelineVisualizer file (*.pvl)");
    loadTemplate(path);

}

void MainProgram::PGSelected(ProcessGraphics *pg){
    selectedPG=pg;
    if(pg==0){
        thepropertymodel->setPGProperty(QMap<QString,QString>());
    }else{
        thepropertymodel->setPGProperty(pg->getProvider()->getSettings(pg));
    }
}

void MainProgram::PropertyChangeSuggested(QMap<QString, QString> thenewsetting){
    if(selectedPG==0)return;
    QString newname=thenewsetting["Name"];
    int i=0;
    QList<ProcessGraphics*> thepg=pvis->getProcessGraphics();
    thepg.removeAll(selectedPG);
    foreach(ProcessGraphics* pg,thepg){
        if(pg->getName()==newname){
            return;
        }
    }
    ProcessGraphics* thenewone=selectedPG->getProvider()->newInstance(thenewsetting);
    ProcessGraphics* thenewpg=thenewone;
    if(thenewpg!=0){
                    int xpos=selectedPG->x();
                    int ypos=selectedPG->y();
                    pvis->addPG(thenewpg,false);
                    thenewpg->setPos(xpos,ypos);
    }else{
        return;
    }
    QList<PipeTarget*> thetargets=selectedPG->getTarget();
    i=0;
    while(i<thetargets.count()){
        if(!thetargets.at(i)->isAvailable()){
            thetargets.at(i)->getFeed()->ApplyTarget(thenewone->getTarget().at(i));
        }
        i=i+1;
    }
    QList<PipeProvider*> providers=selectedPG->getPipeProvider();
    i=0;
    while(i<providers.count()){
        QList<PipeFeed*> thefeeds=providers.at(i)->getFeedlist();
        foreach(PipeFeed* feed,thefeeds){
            PipeTarget* thetarget=feed->curtarget;
            feed->removeMe();
            thenewone->getPipeProvider().at(i)->getNewFeed()->ApplyTarget(thetarget);
        }

        i=i+1;
    }
    selectedPG->removeMe();
    selectedPG=thenewone;
    thenewone->setSelected(true);
    thepropertymodel->setPGProperty(thenewsetting);
}
