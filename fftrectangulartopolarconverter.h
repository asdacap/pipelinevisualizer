#ifndef FFTRECTANGULARTOPOLARCONVERTER_H
#define FFTRECTANGULARTOPOLARCONVERTER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class FFTRectangularToPolarConverter:public SignalProcessor
{
public:
    FFTRectangularToPolarConverter();
    void feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter);
};

class FFTRectangularToPolarConverterProvider:public PipeProcessGraphicsProvider{
public:
    FFTRectangularToPolarConverterProvider(PVisual* pv){
        PV=pv;
    }

    QString getName(){
        return "FFTRectangularToPolarConverter";
    }

    PVisual* PV;
    ProcessGraphics* newInstance(QString name){
        return new WidgetedProcessGraphics(new FFTRectangularToPolarConverter(),name,1,1,2,0,1,0,PV,this);
    }
};

#endif // FFTRECTANGULARTOPOLARCONVERTER_H
