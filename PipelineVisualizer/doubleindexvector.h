#ifndef DOUBLEINDEXVECTOR_H
#define DOUBLEINDEXVECTOR_H
#include <QVector>

class DoubleIndexVector
{
public:
    DoubleIndexVector(QVector<double> dat);
    QVector<double> getData();
    double at(double index);
    QVector<double> data;
};

#endif // DOUBLEINDEXVECTOR_H
