#ifndef PIPEPROVIDERPROVIDER_H
#define PIPEPROVIDERPROVIDER_H
#include <QString>
#include <processgraphics.h>

typedef struct ProcessGraphics ProcessGraphics;

class PipeProcessGraphicsProvider
{
public:
    PipeProcessGraphicsProvider();
    virtual QString getName();
    virtual ProcessGraphics* newInstance();
    QString nameCandidate();
private:
    int counter;
};

#endif // PIPEPROVIDERPROVIDER_H
