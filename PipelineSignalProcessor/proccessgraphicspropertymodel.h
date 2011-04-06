#ifndef PROCCESSGRAPHICSPROPERTYMODEL_H
#define PROCCESSGRAPHICSPROPERTYMODEL_H
#include "QAbstractTableModel"

class ProccessGraphicsPropertyModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    ProccessGraphicsPropertyModel();
    void setPGProperty(QMap<QString,QString> data);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
private:
    QMap<QString,QString> thedata;
signals:
    void PropertySuggested(QMap<QString,QString> newproperty);
};

#endif // PROCCESSGRAPHICSPROPERTYMODEL_H
