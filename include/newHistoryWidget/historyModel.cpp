#include "historyModel.hpp"

#include <QIcon>
#include <QFile>
#include <QDir>

HistoryModel::HistoryModel(const QString &name, QObject *parent)
    : _name(name) ,QAbstractTableModel(parent)
{

}

int HistoryModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return objects.size();
}

int HistoryModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    int indexRow = index.row();

    switch(role){
    case Qt::DisplayRole:
        switch(index.column()){
        case 0:
            return objects.at(indexRow).getCommand();
        case 1:
            return objects.at(indexRow).getTime();
        }
    }
    return QVariant();
}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return "Команда";
        case 1:
            return "Время";
        }
    }

    if(role == Qt::DecorationRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QIcon(":/commands.png");
        case 1:
            return QIcon(":/time.png");
        }
    }

    return QVariant();
}

void HistoryModel::appendObject(const HistoryObject &object)
{
    int row = objects.size();
    beginInsertRows(QModelIndex(), row, row);
    objects.append(object);
    endInsertRows();
}


