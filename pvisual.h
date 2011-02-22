#ifndef PVISUAL_H
#define PVISUAL_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include "pipeproviderprovider.h"
#include <QList>
#include <QComboBox>
#include <QLineEdit>
#include "pipeproviderprovider.h"
#include "targetcollection.h"
#include "QPushButton"
#include "tinyxml/tinyxml.h"

typedef struct PipeProcessGraphicsProvider PipeProcessGraphicsProvider;

namespace Ui {
    class PVisual;
}

class PVisual : public QMainWindow
{
    Q_OBJECT

public:
    explicit PVisual(QWidget *parent = 0);
    void InitializeProvider();
    ~PVisual();
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
    Ui::PVisual *ui;
    TargetCollection* sigcol;
    TargetCollection* doubcol;
    TargetCollection* boolcol;
    void loadPg(TiXmlElement* elm);
    void loadSignalConnection(TiXmlElement* elm);
    void loadDoubleConnection(TiXmlElement* elm);
    void loadBoolConnection(TiXmlElement* elm);
    ProcessGraphics* getProcessGraphics(QString name);

    QAction* loadAction;
    QAction* saveAction;
    QAction* zoomInAction;
    QAction* zoomOutAction;
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
};

class AddSPButton:public QPushButton{
    Q_OBJECT
public:

    AddSPButton(QString provstring,PVisual* pv);
    PVisual* PV;
public slots:
    void AddProv();
};

#endif // PVISUAL_H
