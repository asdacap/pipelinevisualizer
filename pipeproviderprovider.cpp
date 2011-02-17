#include "pipeproviderprovider.h"

PipeProcessGraphicsProvider::PipeProcessGraphicsProvider(){

}

QString PipeProcessGraphicsProvider::getName(){
    return "NullName";
}

ProcessGraphics* PipeProcessGraphicsProvider::newInstance(){
    return 0;
}
