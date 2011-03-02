#include "pluginlisteditor.h"
#include "ui_pluginlisteditor.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <iostream>

PluginListEditor::PluginListEditor(QString path) :
    ui(new Ui::PluginListEditor)
{
    ui->setupUi(this);
    filepath=path;
    QFile thefile(path);
    thefile.open(QIODevice::ReadOnly);
    QTextStream reader(&thefile);
    ui->plainTextEdit->document()->setPlainText(reader.readAll());
    QAction* newpluginAct=new QAction("NewPlugin",this);
    connect(newpluginAct,SIGNAL(triggered()),SLOT(newPlugin()));
    menuBar()->addAction(newpluginAct);
    newpluginAct=new QAction("Save",this);
    connect(newpluginAct,SIGNAL(triggered()),SLOT(saveIt()));
    menuBar()->addAction(newpluginAct);
}

PluginListEditor::~PluginListEditor()
{
    delete ui;
}

void PluginListEditor::newPlugin(){
    QString filepath=QFileDialog::getOpenFileName();
    std::cout<<QApplication::applicationDirPath().toAscii().data()<<std::endl;
    filepath=QDir(QApplication::applicationDirPath()).relativeFilePath(filepath);
    QString wholedoc=ui->plainTextEdit->document()->toPlainText();
    ui->plainTextEdit->document()->setPlainText(wholedoc+"\n"+filepath);
}

void PluginListEditor::saveIt(){
    QFile::remove(filepath);
    QFile thefile(filepath);
    thefile.open(QIODevice::WriteOnly);
    QTextStream writer(&thefile);
    QString text=ui->plainTextEdit->document()->toPlainText();
    writer<<text;
}
