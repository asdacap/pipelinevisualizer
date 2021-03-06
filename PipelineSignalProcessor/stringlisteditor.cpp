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

#include "stringlisteditor.h"
#include "ui_stringlisteditor.h"
#include "QFileDialog"
#include <iostream>

StringlistEditor::StringlistEditor(QList<QString> thelist,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StringlistEditor)
{
    ui->setupUi(this);
    themodel=new QStringListModel(QStringList(thelist),this);
    ui->listView->setModel(themodel);
    connect(ui->addPluginpushButton,SIGNAL(clicked()),SLOT(addButton()));
    connect(ui->RemovePluginAddButton,SIGNAL(clicked()),SLOT(removeButton()));
}

StringlistEditor::~StringlistEditor()
{
    delete ui;
}

QList<QString> StringlistEditor::currentList(){
    return themodel->stringList();
}

void StringlistEditor::addButton(){
    QString filepath=QFileDialog::getOpenFileName();
    filepath=QDir(QApplication::applicationDirPath()).relativeFilePath(filepath);
    themodel->insertRow(0);
    themodel->setData(themodel->index(0,0),QVariant(filepath));
}

void StringlistEditor::removeButton(){
    themodel->removeRow(ui->listView->selectionModel()->currentIndex().row());
}
