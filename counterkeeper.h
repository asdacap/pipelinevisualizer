#ifndef COUNTERKEEPER_H
#define COUNTERKEEPER_H
#include <QList>

class KeyValPair{
public:
    int counter;
    void* data;
};

class KeyValPairComp{
public:
    int counter;
    void** data;
};

class CounterKeeper
{
public:
    CounterKeeper(int dlength);
    void addKey(int index,int counter,void* data);
    bool isAvail(int counter);
    int theLength();
    void** getObject(int counter);

private:
    void* getObject(int index,int counter);
    bool isAvail(int index,int counter);
    int clength;
    QList< QList<KeyValPair>* > dat;
    QList<KeyValPairComp> comleteDat;

};

#endif // COUNTERKEEPER_H
