#include "pipeproviderprovider.h"

PipeProcessGraphicsProvider::PipeProcessGraphicsProvider(){
    counter=0;
}

QString PipeProcessGraphicsProvider::getName(){
    return "NullName";
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(){
    return 0;
}

QString PipeProcessGraphicsProvider::nameCandidate(){
    counter=counter+1;
    return getName()+QVariant(counter).toString();
}
