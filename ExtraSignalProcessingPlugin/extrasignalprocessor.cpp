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
