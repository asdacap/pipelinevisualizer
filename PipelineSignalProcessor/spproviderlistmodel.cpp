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
#include "spproviderlistmodel.h"
#include "QStringList"

SPProviderListModel::SPProviderListModel()
{
}

int SPProviderListModel::rowCount(const QModelIndex &parent) const{
    if(parent==QModelIndex())
        return theproviderlist.count();
    return 0;
}

int SPProviderListModel::columnCount(const QModelIndex &parent) const{
    return 1;
}

QModelIndex SPProviderListModel::index(int row, int column, const QModelIndex &parent) const{
    if(parent==QModelIndex()){
        return createIndex(row,column,theproviderlist.at(row));
    }else{
        return QModelIndex();
    }
}

QModelIndex SPProviderListModel::parent(const QModelIndex &child) const{
    return QModelIndex();
}

QVariant SPProviderListModel::data(const QModelIndex &index, int role) const{
    if(role==Qt::DisplayRole){
        if(index==QModelIndex())return QVariant();
        if(theproviderlist.contains((PipeProcessGraphicsProvider*)index.internalPointer())){
            PipeProcessGraphicsProvider* theprovider=(PipeProcessGraphicsProvider*)index.internalPointer();
            return QVariant(theprovider->getName());
        }
    }
    return QVariant();
}

PipeProcessGraphicsProvider* SPProviderListModel::getTheprov(QString name){
    foreach(PipeProcessGraphicsProvider* theprov,theproviderlist){
        if(theprov->getName()==name)return theprov;
    }
    return 0;
}

void SPProviderListModel::sort(int column, Qt::SortOrder order){
    if(column==0){
        QStringList namelist;
        foreach(PipeProcessGraphicsProvider* theprov,theproviderlist){
            namelist.append(theprov->getName());
        }
        namelist.sort();
        QList<PipeProcessGraphicsProvider*> thenewlist;
        if(order==Qt::DescendingOrder){
            int i=namelist.count()-1;
            while(i>=0){
                thenewlist.append(getTheprov(namelist.at(i)));
                i=i-1;
            }
        }else{
            int i=0;
            while(i<namelist.count()){
                thenewlist.append(getTheprov(namelist.at(i)));
                i=i+1;
            }
        }
        theproviderlist=thenewlist;
        reset();
    }
}

QVariant SPProviderListModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(orientation==Qt::Horizontal&&role==Qt::DisplayRole){
        return QVariant("SignalProcessor Name");
    }
    return QVariant();
}

void SPProviderListModel::filterWithString(QString thestring){
    theproviderlist.clear();
    foreach(PipeProcessGraphicsProvider* theprov,orilist){
        if(theprov->getName().contains(thestring,Qt::CaseInsensitive)){
            theproviderlist.append(theprov);
        }
    }
    reset();
}
