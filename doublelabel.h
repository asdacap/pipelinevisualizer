#ifndef DOUBLELABEL_H
#define DOUBLELABEL_H
#include "QLabel"
#include "QTimer"
#include "doublegenerator.h"
class DoubleLabel: public QLabel
{
    Q_OBJECT
public:
    DoubleLabel(DoubleGenerator* container,QString thelab);
private:
    QString thelabel;
    DoubleGenerator* curd;
    QTimer* curtimer;
    double prev;
public slots:
    void elapsed();
};

#endif // DOUBLELABEL_H
