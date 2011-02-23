#ifndef BLOCKNORMALIZER_H
#define BLOCKNORMALIZER_H
#include "signalprocessor.h"
#include "pipeproviderprovider.h"
#include "widgetedprocessgraphics.h"

class BlockNormalizerProvider;

class BlockNormalizer:public SignalProcessor
{
    friend class BlockNormalizerProvider;
public:
    BlockNormalizer(int onwhat);
    void feedData(QVector<double> dat, int counter, int channel);
    void feedMe(QVector<double>, void *sender);
private:
    int currentCount;
    int division;
};

class BlockNormalizerProvider:public PipeProcessGraphicsProvider{
public:
    BlockNormalizerProvider(PVisual* pv){PV=pv;}
    PVisual* PV;
    QString getName(){return "BlockNormalizer";}
    QMap<QString,QString> defaultSetting();
    QMap<QString,QString> getSettings(ProcessGraphics *pg);
    ProcessGraphics* newInstance(QMap<QString, QString> setting);

};

#endif // BLOCKNORMALIZER_H
