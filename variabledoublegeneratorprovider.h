#ifndef VARIABLEDOUBLEGENERATORPROVIDER_H
#define VARIABLEDOUBLEGENERATORPROVIDER_H

#include <QWidget>
#include "pipeproviderprovider.h"
#include "doublegenerator.h"
#include "pvisual.h"

namespace Ui {
    class VariableDoubleGeneratorProvider;
}

class VariableDoubleGeneratorProvider : public PipeProcessGraphicsProvider
{
public:
    explicit VariableDoubleGeneratorProvider(
                                             PVisual* pv);
    ~VariableDoubleGeneratorProvider();

    ProcessGraphics* newInstance();
    QString getName();

private:
    PVisual* PV;
};

#endif // VARIABLEDOUBLEGENERATORPROVIDER_H
