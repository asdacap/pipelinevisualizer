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
#include "hammingwindowmultiplysp.h"
#include "signalblockbuilder.h"
#include "constantdoublegeneratorprovider.h"
#include "blockgenerator.h"
#include "multivectorfunctionpipe.h"
#include "util.h"
#include "selectivevaluepipe.h"
#include "hammingwindowdividesp.h"
#include "blocknormalizer.h"
#include "fftprocessor.h"
#include "signalexpander.h"
#include "fftrectangulartopolarconverter.h"
#include "fftpolartorectangularconverter.h"
#include "inversefftprocessor.h"
#include "selectivesignalelimination.h"
#include "pinknoiseremover.h"
#include "functionpipe.h"
#include "signalpipe.h"
#include "simpleprocessgraphicsprovidertemplate.h"
#include "blocklengthsender.h"
#include "doublemultiply.h"
#include "harmoniccalculator.h"
#include "soundsink.h"
#include "soundfeeder.h"

DefaultSignalProcessor::DefaultSignalProcessor()
{
}

QList<PipeProcessGraphicsProvider*> DefaultSignalProcessor::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> thelist;
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiplyExternal",pv,0,0,2,1,0,0));
    thelist.append(new SoundSinkProvider(pv));
    thelist.append(new SoundFeederProvider(pv));

    thelist.append(new GraphAbstractionProvider(pv));
    thelist.append(new VariableDoubleGeneratorProvider(pv));
    thelist.append(new SignalScalerProvider(pv));
    thelist.append(new BooleanGeneratorProvider(pv));
    thelist.append(new ConditionalOutputSignalPipeProvider(pv));
    thelist.append(new ConditionalInputSignalPipeProvider(pv));
    thelist.append(new PeriodicListFormatterProvider(pv));
    thelist.append(new HammingWindowMultiplySPProvider(pv));
    thelist.append(new SignalBlockBuilderProvider(pv));
    thelist.append(new ConstantDoubleGeneratorProvider(pv));
    thelist.append(new ConstantBlockGenerator(pv));
    thelist.append(new VariableBlockGenerator(pv));
    thelist.append(new MultiVectorFunctionPipeProvider("ConcatenateSignal",2,1,concatenate,pv));
    thelist.append(new MultiVectorFunctionPipeProvider("SubtractSignal",2,1,subtractIt,pv));
    thelist.append(new SelectiveValuePipeProvider(pv));
    thelist.append(new HammingWindowDivideSPProvider(pv));
    thelist.append(new BlockNormalizerProvider(pv));
    thelist.append(new FFTProcessorProvider(pv));
    thelist.append(new SignalExpanderProvider(pv));
    thelist.append(new FFTRectangularToPolarConverterProvider(pv));
    thelist.append(new FFTPolarToRectangularConverterProvider(pv));
    thelist.append(new InverseFFtProcessorProvider(pv));
    thelist.append(new SelectiveSignalEliminationProvider(pv));
    thelist.append(new PinkNoiseRemoverProvider(pv));
    thelist.append(new FunctionPipeProvider("OneIfZeroSignalFilter",oneifzero,pv));
    thelist.append(new SignalPipeProcessorProvider(pv));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<BlockLengthSender>("BlockLengthSender",pv,1,0,0,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiply",pv,0,0,2,1,0,0));
    thelist.append(new SimpleProcessGraphicsProviderTemplate<HarmonicCalculator>("Harmonic Calculator",pv,1,1,2,0,0,0));

    return thelist;
}

Q_EXPORT_PLUGIN2(DefaultSignalProcessor,DefaultSignalProcessor)
