#pragma once

#include <QAbstractListModel>
#include "commanditem.hpp"

class CommandModel : public QAbstractListModel{
    Q_OBJECT

public:
    explicit CommandModel(QObject *parent = nullptr);

private:
    QList<CommandItem> commands;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    CommandItem getCommandItem(int index) const;
    CommandItem getCommandItem(const QString& command) const;
    bool containsCommand(const QString& command);
};
