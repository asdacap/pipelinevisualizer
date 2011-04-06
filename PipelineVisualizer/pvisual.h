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

#ifndef PVISUAL_H
#define PVISUAL_H
#include "targetcollection.h"
#include "pipeproviderprovider.h"
#include "QWidget"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QList>

class PVisual:public QWidget{
    Q_OBJECT

public:
    PVisual();
    ~PVisual();
    void addPG(ProcessGraphics* pg,bool checkname=true);
    void removePG(ProcessGraphics* );
    bool isExistPGName(QString name);
    ProcessGraphics* getProcessGraphics(QString name);
    QList<ProcessGraphics*> getProcessGraphics(){return pgraphics_list;}
    TargetCollection* getSignalTargetCollection();
    TargetCollection* getDoubleTargetCollection();
    TargetCollection* getBoolTargetCollection();

private:

    QAction* zoomInAction;
    QAction* zoomOutAction;
    QGraphicsScene* scene;
    QGraphicsView* view;
    TargetCollection* sigcol;
    TargetCollection* doubcol;
    TargetCollection* boolcol;
    QList<ProcessGraphics*> pgraphics_list;
    QList<QGraphicsItem*> prevselectedlist;

public slots:
    void theSelectedHasChanged();
    void zoomIn();
    void zoomOut();
    void startButton();
    void stopButton();
    void removeAllButton();

signals:
    void PGSelected(ProcessGraphics* pg);
};

#endif // PVISUAL_H
