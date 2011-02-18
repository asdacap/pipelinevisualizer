#include <QtGui/QApplication>
#include "pvisual.h"
#include "StaticData.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Initialize();
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
