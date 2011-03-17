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
    void addPG(ProcessGraphics* pg);
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

public slots:

    void zoomIn();
    void zoomOut();
    void startButton();
    void stopButton();
    void removeAllButton();
};

#endif // PVISUAL_H
