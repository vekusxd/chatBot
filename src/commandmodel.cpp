#include "../include/commandmodel.hpp"
#include "../include/mathWidgets/add.hpp"
#include "../include/mathWidgets/div.hpp"
#include "../include/mathWidgets/mult.hpp"
#include "../include/mathWidgets/sub.hpp"
#include "../include/clearWidget/clearWidget.hpp"


CommandModel::CommandModel(QObject *parent)
    : QAbstractListModel(parent)
{
    commands.emplaceBack(CommandItem("/сложить", "Сложение двух чисел", new AddWidget, QIcon(":/сложи.png")));
    commands.emplaceBack(CommandItem("/разделить", "Деление двух чисел", new DivWidget, QIcon(":/раздели.png")));
    commands.emplaceBack(CommandItem("/умножить", "Умножение двух чисел", new MultWidget, QIcon(":/умножь.png")));
    commands.emplaceBack(CommandItem("/вычесть", "Вычитание двух чисел", new SubWidget, QIcon(":/вычти.png")));
    commands.emplaceBack(CommandItem("/очистить", "Очистить вывод", new ClearWidget, QIcon(":/clear.png")));
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




