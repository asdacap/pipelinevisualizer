/*
    Copyright 2010-2011 Muhd Amirul Ashraf <asdacap@gmail.com>

    This file is part of PipelineVisualizer.

    PipelineVisualizer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation.

    PipelineVisualizer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PipelineVisualizer.  If not, see <http://www.gnu.org/licenses/>.

*/

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

    void realign();

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
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // PROCESSGRAPHICS_H
