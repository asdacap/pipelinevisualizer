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
