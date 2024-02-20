#pragma once

#include <QListView>
#include <QWidget>
//#include "helpcommandsmodel.hpp"
#include "commandmodel.hpp"

class HelpCommandsWidget : public QWidget{
    Q_OBJECT

public:
    explicit HelpCommandsWidget(QWidget *parent = nullptr);
    QStringList getCommands();
    QListView *view;

signals:
    void sendClickedCommand(const QString& command);

private slots:
    void onDoubleClickedView(const QModelIndex& index);
private:
    CommandModel *model;
};
