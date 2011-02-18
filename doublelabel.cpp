#include "doublelabel.h"
#include "QVariant"

DoubleLabel::DoubleLabel(DoubleGenerator *container, QString thelab){
    curd=container;
    thelabel=thelab;
    curtimer=new QTimer();
    curtimer->setSingleShot(false);
    curtimer->setInterval(100);
    QObject::connect(curtimer,SIGNAL(timeout()),this,SLOT(elapsed()));
    curtimer->start();
}

void DoubleLabel::elapsed(){
    double thedata=curd->getValue();
    if(thedata==prev)return;
    setText(thelabel+QVariant(thedata).toString());
    prev=thedata;
}
