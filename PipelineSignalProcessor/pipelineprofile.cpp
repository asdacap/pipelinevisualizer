#include "pipelineprofile.h"
#include "processgraphics.h"
#include "pipeprovider.h"

PipelineProfile::PipelineProfile(TiXmlDocument *mydoc){
    TiXmlElement* pgelement=(TiXmlElement*)mydoc->FirstChildElement("ProcessGraphics");
    TiXmlElement* currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadPg(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc->FirstChildElement("SignalConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadSignalConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc->FirstChildElement("DoubleConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadDoubleConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
    pgelement=(TiXmlElement*)mydoc->FirstChildElement("BoolConnection");
    currentEle=pgelement->FirstChildElement();
    while(currentEle!=0){
        loadBooleanConnection(currentEle);
        currentEle=currentEle->NextSiblingElement();
    }
}

void PipelineProfile::loadPg(TiXmlElement *elm){
    QString name(elm->Value());
    QMap<QString,QString> setting;
    TiXmlAttribute* atrr=elm->FirstAttribute();
    while(atrr!=NULL){
        setting[QString(atrr->Name())]=QString(atrr->Value());
        atrr=atrr->Next();
    }
    SPProfile theprof;
    theprof.providername=name;
    theprof.settings=setting;
    spprofilelist.append(theprof);
}

ConnectionProfile extractProfile(TiXmlElement* elm){
    TiXmlElement* curelem=elm;

    QString target(curelem->Attribute("target"));
    QString targetId(curelem->Attribute("targetID"));
    QString source(curelem->Attribute("source"));
    QString sourceId(curelem->Attribute("sourceID"));

    ConnectionProfile theprof;
    theprof.source=source;
    theprof.sourceId=QVariant(sourceId).toInt();
    theprof.target=target;
    theprof.targetId=QVariant(targetId).toInt();
    return theprof;
}

void PipelineProfile::loadSignalConnection(TiXmlElement *thel){
    signalConnections.append(extractProfile(thel));
}

void PipelineProfile::loadDoubleConnection(TiXmlElement *thel){
    doubleConnections.append(extractProfile(thel));
}

void PipelineProfile::loadBooleanConnection(TiXmlElement *thel){
    booleanConnections.append(extractProfile(thel));
}

void inline PipelineProfile::loadPg(PVisual* pvis,QList<PipeProcessGraphicsProvider*> prov,SPProfile theprof){
    int i=0;
    while(i<prov.count()){
        if(theprof.providername==prov.at(i)->getName()){
            ProcessGraphics* thenewpg=prov.at(i)->newInstance(theprof.settings);
            if(thenewpg!=0){
                            int xpos=(int)QVariant(theprof.settings["xPos"]).toDouble();
                            int ypos=(int)QVariant(theprof.settings["yPos"]).toDouble();
                            pvis->addPG(thenewpg);
                            thenewpg->setPos(xpos,ypos);
            }
        }
        i=i+1;
    }
}

void inline loadSignalConnections(PVisual* pvis,ConnectionProfile prof){
    ProcessGraphics* targetPG=pvis->getProcessGraphics(prof.target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(prof.source);
    int targetPGID=prof.targetId;
    int sourcePGID=prof.sourceId;
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getSignalPipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getSignalTarget()[targetPGID]);
    }
}

void inline loadDoubleConnections(PVisual* pvis,ConnectionProfile prof){
    ProcessGraphics* targetPG=pvis->getProcessGraphics(prof.target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(prof.source);
    int targetPGID=prof.targetId;
    int sourcePGID=prof.sourceId;
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getDoublePipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getDoublePipeTarget()[targetPGID]);
    }
}

void inline loadBooleanConnections(PVisual* pvis,ConnectionProfile prof){
    ProcessGraphics* targetPG=pvis->getProcessGraphics(prof.target);
    ProcessGraphics* sourcePG=pvis->getProcessGraphics(prof.source);
    int targetPGID=prof.targetId;
    int sourcePGID=prof.sourceId;
    if(targetPG!=0&&sourcePG!=0){
        sourcePG->getBoolPipeProvider()[sourcePGID]->getNewFeed()->ApplyTarget(
                    targetPG->getBoolPipeTarget()[targetPGID]);
    }
}

void PipelineProfile::InitializeIt(PVisual *pvis, QList<PipeProcessGraphicsProvider *> providers){
    int i=0;
    while(i<spprofilelist.count()){
        loadPg(pvis,providers,spprofilelist.at(i));
        i=i+1;
    }
    i=0;
    while(i<signalConnections.count()){
        loadSignalConnections(pvis,signalConnections.at(i));
        i=i+1;
    }
    i=0;
    while(i<doubleConnections.count()){
        loadDoubleConnections(pvis,doubleConnections.at(i));
        i=i+1;
    }
    i=0;
    while(i<booleanConnections.count()){
        loadBooleanConnections(pvis,booleanConnections.at(i));
        i=i+1;
    }
}
