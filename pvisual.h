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

private:
    QGraphicsScene* scene;
    QList<PipeProcessGraphicsProvider*> provider_list;
    Ui::PVisual *ui;
    QComboBox* cbox;
    QLineEdit* le;

public slots:
    void addButton();
};

#endif // PVISUAL_H
