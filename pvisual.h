#ifndef PVISUAL_H
#define PVISUAL_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include "pipeproviderprovider.h"
#include <QList>
#include <QComboBox>
#include <QLineEdit>
#include "pipeproviderprovider.h"
#include "targetcollection.h"

typedef struct PipeProcessGraphicsProvider PipeProcessGraphicsProvider;

namespace Ui {
    class PVisual;
}

class PVisual : public QWidget
{
    Q_OBJECT

public:
    explicit PVisual(QWidget *parent = 0);
    void InitializeProvider();
    ~PVisual();
    void addProvider(PipeProcessGraphicsProvider* prov);
    void addPG(ProcessGraphics* pg);
    void removePG(ProcessGraphics* pg);
    bool isExistPGName(QString name);

    TargetCollection* getSignalTargetCollection();
    TargetCollection* getDoubleTargetCollection();
    TargetCollection* getBoolTargetCollection();

private:
    QGraphicsScene* scene;
    QList<PipeProcessGraphicsProvider*> provider_list;
    QList<ProcessGraphics*> pgraphics_list;
    Ui::PVisual *ui;
    QComboBox* cbox;
    QLineEdit* le;
    TargetCollection* sigcol;
    TargetCollection* doubcol;
    TargetCollection* boolcol;

public slots:
    void addButton();
    void startButton();
    void stopButton();
    void removeAllButton();
};

#endif // PVISUAL_H
