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
