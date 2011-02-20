#ifndef PIPEPROVIDERPROVIDER_H
#define PIPEPROVIDERPROVIDER_H
#include <QString>

class ProcessGraphics;
class PVisual;

class PipeProcessGraphicsProvider
{
public:
    PipeProcessGraphicsProvider();
    virtual QString getName();
    virtual ProcessGraphics* newInstance();
    virtual ProcessGraphics* newInstance(QString name);
    QString nameCandidate();
private:
    int counter;
};

#endif // PIPEPROVIDERPROVIDER_H
