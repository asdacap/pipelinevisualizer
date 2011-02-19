#ifndef VARIABLEDOUBLEGENERATORPROVIDER_H
#define VARIABLEDOUBLEGENERATORPROVIDER_H

#include <QWidget>
#include "pipeproviderprovider.h"
#include "doublegenerator.h"
#include "mainwindow.h"
#include "pvisual.h"

namespace Ui {
    class VariableDoubleGeneratorProvider;
}

class VariableDoubleGeneratorProvider : public PipeProcessGraphicsProvider
{
public:
    explicit VariableDoubleGeneratorProvider(MainWindow* mw,
                                             PVisual* pv);
    ~VariableDoubleGeneratorProvider();

    ProcessGraphics* newInstance();
    QString getName();

private:
    MainWindow* MW;
    PVisual* PV;
};

#endif // VARIABLEDOUBLEGENERATORPROVIDER_H
