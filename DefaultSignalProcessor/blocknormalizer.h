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
