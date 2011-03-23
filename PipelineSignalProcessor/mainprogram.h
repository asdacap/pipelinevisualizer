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

#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QWidget>
#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include "pipeproviderprovider.h"
#include "targetcollection.h"
#include "QPushButton"
#include "tinyxml/tinyxml.h"
#include "pvisual.h"
#include "QTreeView"
#include "QListWidget"
#include "spproviderlistmodel.h"
#include <pipelineprofile.h>

typedef struct PipeProcessGraphicsProvider PipeProcessGraphicsProvider;

class MainProgram : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainProgram(QWidget *parent = 0);
    void InitializeProvider();
    ~MainProgram();
    void addProvider(PipeProcessGraphicsProvider* prov);
    bool isExistProviderName(QString name);
    void addPG(QString providername);


private:
    QList<PipeProcessGraphicsProvider*> provider_list;
    void loadDefaultPlugin();
    void loadPlugin(QString filepath);

    PVisual* pvis;
    QAction* loadAction;
    QAction* saveAction;
    QAction* loadPluginAction;
    QAction* pluginListAction;

    QTreeView* addSPwidget;
    SPProviderListModel* providerlistmodel;

public slots:
    void saveButton();
    void loadButton();

    void loadPlugin();
    void openPluginListEditor();

    void listDoubleClicked(QModelIndex modeindex);
};

#endif // MAINPROGRAM_H
