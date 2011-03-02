#include <QtGui/QApplication>
#include "pvisual.h"
#include "mainprogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainProgram w;
    w.show();

    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
