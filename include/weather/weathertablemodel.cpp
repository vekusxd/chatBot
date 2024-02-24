#include "weathertablemodel.hpp"

#include <QFont>
#include <QIcon>

WeatherModel::WeatherModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int WeatherModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return objects.size();
}

int WeatherModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant WeatherModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    int indexRow = index.row();

    switch(role){
    case Qt::DisplayRole:
        switch(index.column()){
        case 0:
            return objects.at(indexRow).getCityName();
        case 1:
            return objects.at(indexRow).getTemp();
        case 2:
            return objects.at(indexRow).getFeelsLike();
        case 3:
            return objects.at(indexRow).getPressure();
        case 4:
            return objects.at(indexRow).getHumidity();
        case 5:
            return objects.at(indexRow).getWindSpeed();
        case 6:
            return objects.at(indexRow).getTime();
        }

    }
    return QVariant();
}

QVariant WeatherModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return "Город";
        case 1:
            return "Температура";
        case 2:
            return "Ощущается \nкак";
        case 3:
            return "Давление";
        case 4:
            return "Влажность";
        case 5:
            return "Скорость \nветра";
        case 6:
            return "Время";
        }
    }

    if(role == Qt::DecorationRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QIcon(":/cityIcon.png");
        case 1:
            return QIcon(":/temperature.png");
        case 3:
            return QIcon(":/pressure.png");
        case 4:
            return QIcon(":/влажность.png");
        case 5:
            return QIcon(":/wind.png");
        case 6:
            return QIcon(":/time.png");
        }
    }

    return QVariant();
}

void WeatherModel::appendObject(const WeatherObject &object)
{
    int row = objects.size();
    beginInsertRows(QModelIndex(), row, row);
    objects.append(object);
    endInsertRows();
}
