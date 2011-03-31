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

#ifndef PIPEPROVIDERPROVIDER_H
#define PIPEPROVIDERPROVIDER_H
#include <QString>
#include <QMap>

class ProcessGraphics;
class PVisual;

class PipeProcessGraphicsProvider
{
public:
    PipeProcessGraphicsProvider(PVisual* pvusr);
    virtual QString getName()=0;
    virtual QMap<QString,QString> defaultSetting();
    virtual ProcessGraphics* newInstance();
    virtual ProcessGraphics* newInstance(QString name);
    virtual QMap<QString,QString> getSettings(ProcessGraphics* pg);
    virtual ProcessGraphics* newInstance(QMap<QString,QString> setting);
    virtual QString getToolTip();
    virtual QString getProviderToolTip(int id);
    virtual QString getTargetToolTip(int id);
    QString nameCandidate();
private:
    PVisual* pv;
    int counter;
};

#endif // PIPEPROVIDERPROVIDER_H
