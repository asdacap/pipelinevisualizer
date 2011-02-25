#include <QtGui/QApplication>
#include "pvisual.h"
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PVisual w;
    w.addProvider(new GraphAbstractionProvider(&w));
    w.addProvider(new VariableDoubleGeneratorProvider(&w));
    w.addProvider(new SignalScalerProvider(&w));
    w.addProvider(new BooleanGeneratorProvider(&w));
    w.addProvider(new ConditionalOutputSignalPipeProvider(&w));
    w.addProvider(new ConditionalInputSignalPipeProvider(&w));
    w.addProvider(new PeriodicListFormatterProvider(&w));
    w.addProvider(new HammingWindowMultiplySPProvider(&w));
    w.addProvider(new SignalBlockBuilderProvider(&w));
    w.addProvider(new ConstantDoubleGeneratorProvider(&w));
    w.addProvider(new ConstantBlockGenerator(&w));
    w.addProvider(new VariableBlockGenerator(&w));
    w.addProvider(new MultiVectorFunctionPipeProvider("ConcatenateSignal",2,1,concatenate,&w));
    w.addProvider(new MultiVectorFunctionPipeProvider("SubtractSignal",2,1,subtractIt,&w));
    w.addProvider(new SelectiveValuePipeProvider(&w));
    w.addProvider(new HammingWindowDivideSPProvider(&w));
    w.addProvider(new BlockNormalizerProvider(&w));
    w.addProvider(new FFTProcessorProvider(&w));
    w.addProvider(new SignalExpanderProvider(&w));
    w.addProvider(new FFTRectangularToPolarConverterProvider(&w));
    w.addProvider(new FFTPolarToRectangularConverterProvider(&w));
    w.addProvider(new InverseFFtProcessorProvider(&w));
    w.addProvider(new SelectiveSignalEliminationProvider(&w));
    w.addProvider(new PinkNoiseRemoverProvider(&w));
    w.addProvider(new FunctionPipeProvider("OneIfZeroSignalFilter",oneifzero,&w));
    w.addProvider(new SignalPipeProcessorProvider(&w));
    w.addProvider(new SimpleProcessGraphicsProviderTemplate<BlockLengthSender>("BlockLengthSender",&w,1,0,0,1,0,0));
    w.addProvider(new SimpleProcessGraphicsProviderTemplate<DoubleMultiply>("DoubleMultiply",&w,0,0,2,1,0,0));
    w.show();

    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
