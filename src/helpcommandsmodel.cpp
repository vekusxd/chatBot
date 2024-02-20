#include "../include/helpcommandsmodel.hpp"

#include <QIcon>


HelpCommandsModel::HelpCommandsModel(QObject *parent)
    : QAbstractListModel(parent)
{
    commands << "/погода" << "сложи" << "раздели"
             << "умножь" << "вычти";
}

int HelpCommandsModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return commands.size();
}

QVariant HelpCommandsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    int rowIndex = index.row();
    switch(role){
    case Qt::DisplayRole:
        return commands.at(rowIndex);
    case Qt::DecorationRole:
        return QIcon(":/" + commands.at(rowIndex) + ".png");
    case Qt::ToolTipRole:
        if(commands.at(rowIndex) == "/погода"){
            return QString("Узнать текущую погоду в заданном городе");
        }
        if(commands.at(rowIndex) == "сложи"){
            return QString("Сложить 2 числа, писать в формате \"сложи 2 и 4\"");
        }
        if(commands.at(rowIndex) == "вычти"){
            return QString("Вычесть 2 числа, писать в формате \"вычти 4 и 2\"");
        }
        if(commands.at(rowIndex) == "умножь"){
            return QString("Умножить 2 числа, писать в формате \"умножь 2 и 4\"");
        }
        if(commands.at(rowIndex) == "раздели"){
            return QString("Разделить 2 числа, писать в формате \"раздели 4 на 2\"");
        }
    }
    return QVariant();

}

QStringList HelpCommandsModel::getCommands() const
{
    return commands;
}




