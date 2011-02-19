#ifndef BOOLEANGENERATORPROVIDER_H
#define BOOLEANGENERATORPROVIDER_H
#include "booleangenerator.h"
#include "pipeproviderprovider.h"
#include "mainwindow.h"
#include "pvisual.h"

class BooleanGeneratorProvider:public PipeProcessGraphicsProvider
{
public:
    BooleanGeneratorProvider(MainWindow* mw,PVisual* pv);
    QString getName();
    ProcessGraphics* newInstance();

    MainWindow* MW;
    PVisual* PV;
};

#endif // BOOLEANGENERATORPROVIDER_H
