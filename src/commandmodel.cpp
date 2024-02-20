#include "../include/commandmodel.hpp"
#include "../include/mathWidgets/add.hpp";


CommandModel::CommandModel(QObject *parent)
    : QAbstractListModel(parent)
{
    commands.emplaceBack(CommandItem("/сложить", "Сложение двух чисел", new AddWidget, QIcon(":/сложи.png")));
}

int CommandModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return commands.size();
}

QVariant CommandModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    int rowIndex = index.row();
    switch(role){
    case Qt::DisplayRole:
        return commands.at(rowIndex).getTitle();
    case Qt::DecorationRole:
        return commands.at(rowIndex).getIcon();
    case Qt::ToolTipRole:
        return commands.at(rowIndex).getToolTipText();
    }
    return QVariant();
}

CommandItem CommandModel::getCommandItem(int index) const
{
    return commands.at(index);
}

CommandItem CommandModel::getCommandItem(const QString &command) const
{
    for(const auto& item : commands){
        if(item.getTitle() == command){
            return item;
        }
    }
}

bool CommandModel::containsCommand(const QString &command)
{
    for(const auto& item : commands){
        if(item.getTitle() == command){
            return true;
        }
    }
    return false;
}




