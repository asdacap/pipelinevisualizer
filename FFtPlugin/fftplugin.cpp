#include "fftplugin.h"
#include "fftprocessor.h"
#include "fftpolartorectangularconverter.h"
#include "fftrectangulartopolarconverter.h"
#include "inversefftprocessor.h"

FFtPlugin::FFtPlugin()
{
}

QList<PipeProcessGraphicsProvider*> FFtPlugin::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> thelist;
    thelist.append(new FFTProcessorProvider(pv));
    thelist.append(new FFTRectangularToPolarConverterProvider(pv));
    thelist.append(new FFTPolarToRectangularConverterProvider(pv));
    thelist.append(new InverseFFtProcessorProvider(pv));
    return thelist;
}

Q_EXPORT_PLUGIN2(FFtPlugin,FFtPlugin)
