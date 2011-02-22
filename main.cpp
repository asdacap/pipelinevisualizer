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
    w.show();

    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
