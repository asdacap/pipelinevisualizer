#include "booleanlabel.h"

BooleanLabel::BooleanLabel(BooleanGenerator *container, QString thelab):QLabel(){
    curd=container;
    thelabel=thelab;
    curtimer=new QTimer();
    curtimer->setSingleShot(false);
    curtimer->setInterval(100);
    QObject::connect(curtimer,SIGNAL(timeout()),this,SLOT(elapsed()));
    curtimer->start();
    setText(thelab);
}

void BooleanLabel::elapsed(){
    bool thedata=curd->getValue();
    if(thedata==prev)return;

    if(thedata){
        setBackgroundRole(QPalette::Highlight);
        setForegroundRole(QPalette::Highlight);
    }else{
        setBackgroundRole(QPalette::NoRole);
        setForegroundRole(QPalette::NoRole);
    }

    prev=thedata;
}
