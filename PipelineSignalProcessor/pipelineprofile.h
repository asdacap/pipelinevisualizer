#ifndef PIPELINEPROFILE_H
#define PIPELINEPROFILE_H
#include "QtCore"
#include "tinyxml/tinyxml.h"
#include "pvisual.h"

class SPProfile{
public:
    QString providername;
    QMap<QString,QString> settings;
};

class ConnectionProfile{
public:
    QString target;
    int targetId;
    QString source;
    int sourceId;
};

class PipelineProfile
{
public:
    PipelineProfile(TiXmlDocument* thedoc);
    void InitializeIt(PVisual* pvis,QList<PipeProcessGraphicsProvider*> providers);
private:
    void loadPg(TiXmlElement* thel);
    void loadPg(PVisual* pvis,QList<PipeProcessGraphicsProvider*> prov,SPProfile theprof);
    void loadSignalConnection(TiXmlElement* thel);
    void loadDoubleConnection(TiXmlElement* thel);
    void loadBooleanConnection(TiXmlElement* thel);
    QList<SPProfile> spprofilelist;
    QList<ConnectionProfile> signalConnections;
    QList<ConnectionProfile> doubleConnections;
    QList<ConnectionProfile> booleanConnections;
};


#endif // PIPELINEPROFILE_H
