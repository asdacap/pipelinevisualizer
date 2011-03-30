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
#ifndef SPPROVIDERLISTMODEL_H
#define SPPROVIDERLISTMODEL_H
#include "QAbstractItemModel"
#include "pipeproviderprovider.h"

class SPProviderListModel:public QAbstractItemModel
{
    Q_OBJECT
public:
    SPProviderListModel();
    void addProvider(PipeProcessGraphicsProvider* newprovider){
        orilist.append(newprovider);
        filterWithString("");
    }
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void sort(int column, Qt::SortOrder order);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    PipeProcessGraphicsProvider* getTheprov(QString name);
    QList<PipeProcessGraphicsProvider*> theproviderlist;
    QList<PipeProcessGraphicsProvider*> orilist;
public slots:
    void filterWithString(QString thestring);
};

#endif // SPPROVIDERLISTMODEL_H
