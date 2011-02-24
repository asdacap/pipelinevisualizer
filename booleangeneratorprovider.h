#ifndef BOOLEANGENERATORPROVIDER_H
#define BOOLEANGENERATORPROVIDER_H
#include "booleangenerator.h"
#include "pipeproviderprovider.h"

class PVisual;

class BooleanGeneratorProvider:public PipeProcessGraphicsProvider
{
public:
    BooleanGeneratorProvider(PVisual* pv);
    QString getName();
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString,QString> setting);

    PVisual* PV;
};

#endif // BOOLEANGENERATORPROVIDER_H
