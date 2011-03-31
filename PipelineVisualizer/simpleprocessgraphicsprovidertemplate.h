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

#ifndef SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
#define SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

template<class P>
class SimpleProcessGraphicsProviderTemplate:public PipeProcessGraphicsProvider
{
public:
    SimpleProcessGraphicsProviderTemplate(QString name,PVisual* pv,
                                          int sin,int sout,int din,int dout,
                                          int bin,int bout):
    PipeProcessGraphicsProvider(pv){
        this->name=name;
        PV=pv;
        sinput=sin;
        soutput=sout;
        dinput=din;
        doutput=dout;
        binput=bin;
        boutput=bout;
}

    QString name;
    int sinput;
    int soutput;
    int dinput;
    int doutput;
    int binput;
    int boutput;
    PVisual* PV;
    QString getName(){return name;}
    ProcessGraphics* newInstance(QString s){
        P* prov=new P();
        return new WidgetedProcessGraphics(prov,s,sinput,soutput,dinput,doutput,binput,boutput,PV,this);
    }
};

#endif // SIMPLEPROCESSGRAPHICSPROVIDERTEMPLATE_H
