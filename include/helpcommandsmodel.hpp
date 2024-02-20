#pragma once

#include <QAbstractListModel>

class HelpCommandsModel : public QAbstractListModel{
    Q_OBJECT

public:
    explicit HelpCommandsModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QStringList getCommands() const;

    QStringList commands;
};
