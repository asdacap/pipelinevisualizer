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

#include "defaultsignalprocessor.h"
#include "simpleprocessgraphicsprovidertemplate.h"
#include "doublemultiply.h"

#include "variabledoublegeneratorprovider.h"
#include "signalscaler.h"
#include "booleangeneratorprovider.h"
#include "conditionaloutputsignalpipe.h"
#include "widgetedprocessgraphics.h"
#include "graphabstractionprovider.h"
#include "conditionalinputsignalpipe.h"
#include "periodiclistformatter.h"
#include "signalblockbuilder.h"
#include "constantdoublegeneratorprovider.h"
#include "blockgenerator.h"
#include "multivectorfunctionpipe.h"
#include "util.h"
#include "selectivevaluepipe.h"
#include "blocknormalizer.h"
#include "signalexpander.h"
#include "selectivesignalelimination.h"
#include "functionpipe.h"
#include "simpleprocessgraphicsprovidertemplate.h"
#include "blocklengthsender.h"
#include "doublemultiply.h"
#include "signalrepeater.h"
#include "plainsignalpipe.h"
#include "booleanand.h"
#include "booleanor.h"
#include "booleanxor.h"
#include "booleaninvert.h"
#include "doubledivide.h"
#include "doubleinverse.h"
#include "doubleplus.h"
#include "doubleminus.h"
#include "integerdivide.h"
#include "doubleisgreaterthan.h"
#include "doubleislessthan.h"
#include "doubleisequal.h"
#include "signalmultiply.h"
#include "signaldivide.h"
#include "signalinverse.h"
#include "signalplus.h"
#include "signalminus.h"
#include "signaldifferentation.h"
#include "signalintegration.h"

DefaultSignalProcessor::DefaultSignalProcessor()
{
}

QList<PipeProcessGraphicsProvider*> DefaultSignalProcessor::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> thelist;
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiply",pv,0,0,2,1,0,0));
    thelist.append(new GraphAbstractionProvider(pv));
    thelist.append(new VariableDoubleGeneratorProvider(pv));
    thelist.append(new SignalScalerProvider(pv));
    thelist.append(new BooleanGeneratorProvider(pv));
    thelist.append(new ConditionalOutputSignalPipeProvider(pv));
    thelist.append(new ConditionalInputSignalPipeProvider(pv));
    thelist.append(new PeriodicListFormatterProvider(pv));
    thelist.append(new SignalBlockBuilderProvider(pv));
    thelist.append(new ConstantDoubleGeneratorProvider(pv));
    thelist.append(new ConstantBlockGenerator(pv));
    thelist.append(new VariableBlockGenerator(pv));
    thelist.append(new MultiVectorFunctionPipeProvider("ConcatenateSignal",2,1,concatenate,pv));
    thelist.append(new MultiVectorFunctionPipeProvider("SubtractSignal",2,1,subtractIt,pv));
    thelist.append(new SelectiveValuePipeProvider(pv));
    thelist.append(new BlockNormalizerProvider(pv));
    thelist.append(new SignalExpanderProvider(pv));
    thelist.append(new SelectiveSignalEliminationProvider(pv));
    thelist.append(new FunctionPipeProvider("OneIfZeroSignalFilter",oneifzero,pv));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<PlainSignalPipe>("PlainSignalPipe",pv,1,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BlockLengthSender>("BlockLengthSender",pv,1,0,0,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiply",pv,0,0,2,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalRepeater>("SignalRepeater",pv,1,1,1,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BooleanAnd>("BooleanAnd",pv,0,0,0,0,2,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BooleanOr>("BooleanOr",pv,0,0,0,0,2,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BooleanXOr>("BooleanXOr",pv,0,0,0,0,2,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BooleanInvert>("BooleanInvert",pv,0,0,0,0,1,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleDivide>("DoubleDivide",pv,0,0,2,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleInverse>("DoubleInverse",pv,0,0,1,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoublePlus>("DoublePlus",pv,0,0,2,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMinus>("DoubleMinus",pv,0,0,2,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<IntegerDivide>("IntegerDivide",pv,0,0,2,2,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleIsGreaterThan>("DoubleIsGreaterThan",pv,0,0,2,0,0,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleIsLessThan>("DoubleIsLessThan",pv,0,0,2,0,0,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleIsEqual>("DoubleIsEqual",pv,0,0,2,0,0,1));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalMultiply>("SignalMultiply",pv,2,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalDivide>("SignalDivide",pv,2,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalInverse>("SignalInverse",pv,1,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalPlus>("SignalPlus",pv,2,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalMinus>("SignalMinus",pv,2,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalDifferentation>("SignalDifferentation",pv,1,1,0,0,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<SignalIntegration>("SignalIntegration",pv,1,1,0,0,0,0));


    return thelist;
}

Q_EXPORT_PLUGIN2(DefaultSignalProcessor,DefaultSignalProcessor)
