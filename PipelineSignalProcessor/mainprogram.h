#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QList>
#include <QComboBox>
#include <QLineEdit>
#include "pipeproviderprovider.h"
#include "targetcollection.h"
#include "QPushButton"
#include "tinyxml/tinyxml.h"
#include "pvisual.h"

typedef struct PipeProcessGraphicsProvider PipeProcessGraphicsProvider;

class MainProgram : public QMainWindow,public PVisual
{
    Q_OBJECT

public:
    explicit MainProgram(QWidget *parent = 0);
    void InitializeProvider();
    ~MainProgram();
    void addProvider(PipeProcessGraphicsProvider* prov);
    void addPG(ProcessGraphics* pg);
    void addPG(QString providername);
    void removePG(ProcessGraphics* pg);
    bool isExistPGName(QString name);
    bool isExistProviderName(QString name);

    TargetCollection* getSignalTargetCollection();
    TargetCollection* getDoubleTargetCollection();
    TargetCollection* getBoolTargetCollection();

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QList<PipeProcessGraphicsProvider*> provider_list;
    QList<ProcessGraphics*> pgraphics_list;
    TargetCollection* sigcol;
    TargetCollection* doubcol;
    TargetCollection* boolcol;
    void loadDefaultPlugin();
    void loadPlugin(QString filepath);
    void loadPg(TiXmlElement* elm);
    void loadSignalConnection(TiXmlElement* elm);
    void loadDoubleConnection(TiXmlElement* elm);
    void loadBoolConnection(TiXmlElement* elm);
    ProcessGraphics* getProcessGraphics(QString name);

    QAction* loadAction;
    QAction* saveAction;
    QAction* zoomInAction;
    QAction* zoomOutAction;
    QAction* loadPluginAction;
    QAction* pluginListAction;
    double curscale;

    QWidget* addSPwidget;
    QBoxLayout* spwidgetLayout;

public slots:
    void startButton();
    void stopButton();
    void removeAllButton();
    void saveButton();
    void loadButton();
    void zoomIn();
    void zoomOut();
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
