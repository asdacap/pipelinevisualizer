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
