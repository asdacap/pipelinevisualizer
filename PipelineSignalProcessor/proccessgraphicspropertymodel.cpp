#include "proccessgraphicspropertymodel.h"

ProccessGraphicsPropertyModel::ProccessGraphicsPropertyModel()
{
}

void ProccessGraphicsPropertyModel::setPGProperty(QMap<QString, QString> data){
    thedata=data;
    reset();
}

int ProccessGraphicsPropertyModel::columnCount(const QModelIndex &parent) const{
    return 2;
}

int ProccessGraphicsPropertyModel::rowCount(const QModelIndex &parent) const{
    return thedata.count();
}

QVariant ProccessGraphicsPropertyModel::data(const QModelIndex &index, int role) const{
    if(role==Qt::DisplayRole){
        if(index==QModelIndex()){
            return QVariant("");
        }else{
            if(index.column()==0){
                return QVariant(thedata.keys().at(index.row()));
            }else{
                return QVariant(thedata.value(thedata.keys().at(index.row())));
            }
        }
    }
    return QVariant();
}

QVariant ProccessGraphicsPropertyModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role==Qt::DisplayRole){
        if(orientation==Qt::Horizontal){
            if(section==0){
                return QVariant("Property");
            }else{
                return QVariant("Value");
            }

        }
    }
    return QVariant();
}

Qt::ItemFlags ProccessGraphicsPropertyModel::flags(const QModelIndex &index) const{
    if(index.column()==1){
        return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
    }
    return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

bool ProccessGraphicsPropertyModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(index.column()!=1){
        return false;
    }
    QMap<QString,QString> theprop=thedata;
    theprop[theprop.keys().at(index.row())]=value.toString();
    emit PropertySuggested(theprop);
    return true;
}
