#include <QtGui/QApplication>
#include "pvisual.h"
#include "StaticData.h"

int main(int argc, char *argv[])
{
    Initialize();
    QApplication a(argc, argv);
    PVisual w;
    w.show();

    return a.exec();
}
