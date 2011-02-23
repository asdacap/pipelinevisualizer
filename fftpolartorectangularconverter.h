#ifndef FFTPOLARTORECTANGULARCONVERTER_H
#define FFTPOLARTORECTANGULARCONVERTER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class FFTPolarToRectangularConverter:public SignalProcessor
{
public:
    FFTPolarToRectangularConverter();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class FFTPolarToRectangularConverterProvider:public PipeProcessGraphicsProvider{
public:
    FFTPolarToRectangularConverterProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "FFTPolarToRectangularConverter";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new FFTPolarToRectangularConverter(),name,2,2,0,0,0,0,PV,this);
    }
};


#endif // FFTPOLARTORECTANGULARCONVERTER_H
