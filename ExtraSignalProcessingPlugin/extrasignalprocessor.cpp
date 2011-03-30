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
#include "extrasignalprocessor.h"
#include "pinknoiseremover.h"
#include "hammingwindowdividesp.h"
#include "hammingwindowmultiplysp.h"
#include "harmoniccalculator.h"
#include "simpleprocessgraphicsprovidertemplate.h"

ExtraSignalProcessor::ExtraSignalProcessor(){

}

QList<PipeProcessGraphicsProvider*> ExtraSignalProcessor::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> thelist;
    thelist.append(new HammingWindowMultiplySPProvider(pv));
    thelist.append(new HammingWindowDivideSPProvider(pv));
    thelist.append(new PinkNoiseRemoverProvider(pv));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<HarmonicCalculator>("Harmonic Calculator",pv,1,1,2,0,0,0));
    return thelist;
}

Q_EXPORT_PLUGIN2(ExtraSignalProcessor,ExtraSignalProcessor)
