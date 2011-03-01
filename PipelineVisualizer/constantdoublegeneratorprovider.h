#ifndef CONSTANTDOUBLEGENERATORPROVIDER_H
#define CONSTANTDOUBLEGENERATORPROVIDER_H
#include "pipeproviderprovider.h"
#include "signalprocessor.h"
#include "doublegenerator.h"

class ConstantDoubleGeneratorProvider:public PipeProcessGraphicsProvider
{
public:
    ConstantDoubleGeneratorProvider(PVisual* pv);
    PVisual* PV;
    QString getName(){return "ConstantDoubleGenerator";}
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString,QString> setting);
};

#endif // CONSTANTDOUBLEGENERATORPROVIDER_H
