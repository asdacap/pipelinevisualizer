#ifndef BOOLEANLABEL_H
#define BOOLEANLABEL_H
#include "QLabel"
#include "QTimer"
#include "booleangenerator.h"

class BooleanLabel:public QLabel
{
    Q_OBJECT
public:
    BooleanLabel(BooleanGenerator* container,QString thelab);
private:
    QString thelabel;
    BooleanGenerator* curd;
    QTimer* curtimer;
    bool prev;
public slots:
    void elapsed();
};

#endif // BOOLEANLABEL_H
