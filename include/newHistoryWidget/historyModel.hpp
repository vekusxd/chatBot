#pragma once

#include <QAbstractTableModel>

#include "historyObject.hpp"

class HistoryModel : public QAbstractTableModel{
    Q_OBJECT

public:
    explicit HistoryModel(const QString &name, QObject *parent = nullptr);

private:
    QList<HistoryObject> objects;
    QString _name;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void appendObject(const HistoryObject &object);
};
