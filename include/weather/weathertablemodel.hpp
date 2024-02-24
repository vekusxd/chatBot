#pragma once

#include <QAbstractTableModel>

#include "weatherobject.hpp"

class WeatherModel : public QAbstractTableModel{
    Q_OBJECT

public:
    explicit WeatherModel(QObject *parent = nullptr);

private:
    QList<WeatherObject> objects;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    // QAbstractItemModel interface
public:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void appendObject(const WeatherObject& object);
};
