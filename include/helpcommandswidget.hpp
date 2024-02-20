#pragma once

#include <QListView>
#include <QWidget>
#include "helpcommandsmodel.hpp"

class HelpCommandsWidget : public QWidget{
    Q_OBJECT

public:
    explicit HelpCommandsWidget(QWidget *parent = nullptr);
    QStringList getCommands();

signals:
    void sendClickedCommand(const QString& command);

private slots:
    void onDoubleClickedView(const QModelIndex& index);
private:
    QListView *view;
    HelpCommandsModel *model;
};
