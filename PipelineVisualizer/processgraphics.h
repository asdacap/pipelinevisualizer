#ifndef PROCESSGRAPHICS_H
#define PROCESSGRAPHICS_H
#include <QGraphicsObject>
#include <QObject>
#include <QTimer>
#include "QAction"

class PipeProcessGraphicsProvider;
class PipeTarget;
class PipeProvider;
class SignalProcessor;
class PVisual;

class ProcessGraphics:public QGraphicsObject
{
    Q_OBJECT
public:
    ProcessGraphics(SignalProcessor* sp,QString name,PipeProcessGraphicsProvider* prov,
                    int sinput,int soutput,int dinput,int doutput,int binput,int boutput,PVisual* pv);

    SignalProcessor* getProcessor(){
        return processor;
    }

    QString getName(){
        return pgName;
    }

    PipeProcessGraphicsProvider* getProvider(){
        return provider;
    }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void removeMe();

    QList<PipeTarget*> getTarget(){
        return targetCollection;
    }

    QList<PipeProvider*> getPipeProvider(){
        return providerCollection;
    }

    QList<PipeTarget*> getSignalTarget(){
        return signalTargetCollection;
    }

    QList<PipeProvider*> getSignalPipeProvider(){
        return signalProviderCollection;
    }

    QList<PipeTarget*> getDoublePipeTarget(){
        return doubleTargetCollection;
    }

    QList<PipeProvider*> getDoublePipeProvider(){
        return doubleProviderCollection;
    }
    QList<PipeTarget*> getBoolPipeTarget(){
        return boolTargetCollection;
    }

    QList<PipeProvider*> getBoolPipeProvider(){
        return boolProviderCollection;
    }

private:
    SignalProcessor* processor;
    PipeProcessGraphicsProvider* provider;
    QList<PipeTarget*> targetCollection;
    QList<PipeProvider*> providerCollection;
    QList<PipeTarget*> signalTargetCollection;
    QList<PipeProvider*> signalProviderCollection;
    QList<PipeTarget*> doubleTargetCollection;
    QList<PipeProvider*> doubleProviderCollection;
    QList<PipeTarget*> boolTargetCollection;
    QList<PipeProvider*> boolProviderCollection;
protected:
    QString pgName;
    PVisual* pv;
};

#endif // PROCESSGRAPHICS_H
