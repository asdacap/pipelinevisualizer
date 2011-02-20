#include "pipeproviderprovider.h"
#include "QInputDialog"
#include "iostream"
#include "QVariant"

PipeProcessGraphicsProvider::PipeProcessGraphicsProvider(){
    counter=0;
}

QString PipeProcessGraphicsProvider::getName(){
    return "NullName";
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         return newInstance(text);
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }

}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(QString name){
    return 0;
}

QString PipeProcessGraphicsProvider::nameCandidate(){
    counter=counter+1;
    return getName()+QVariant(counter).toString();
}
