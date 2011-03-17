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
    void loadPg(TiXmlElement* elm);
    void loadSignalConnection(TiXmlElement* elm);
    void loadDoubleConnection(TiXmlElement* elm);
    void loadBoolConnection(TiXmlElement* elm);

    PVisual* pvis;
    QAction* loadAction;
    QAction* saveAction;
    QAction* loadPluginAction;
    QAction* pluginListAction;

    QWidget* addSPwidget;
    QBoxLayout* spwidgetLayout;

public slots:
    void saveButton();
    void loadButton();

    void loadPlugin();
    void openPluginListEditor();
};

class AddSPButton:public QPushButton{
    Q_OBJECT
public:

    AddSPButton(QString provstring,MainProgram* pv);
    MainProgram* PV;
public slots:
    void AddProv();
};

#endif // MAINPROGRAM_H
