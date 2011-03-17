/*
    Copyright 2010-2011 Muhd Amirul Ashraf <asdacap@gmail.com>

    This file is part of PipelineVisualizer.

    PipelineVisualizer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation.

    PipelineVisualizer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PipelineVisualizer.  If not, see <http://www.gnu.org/licenses/>.

*/

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
