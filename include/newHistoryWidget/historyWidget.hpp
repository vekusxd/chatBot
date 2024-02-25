#include <QWidget>
#include <QTableView>
#include <QSortFilterProxyModel>

#include "historyModel.hpp"

class HistoryWidget : public QWidget{
public:
    explicit HistoryWidget(const QString& name, QWidget *parent = nullptr);

public:
    void addObject(const QString& command, const QString& time);

public slots:
    void onTextChanged();

private:
    HistoryModel *model;
    QTableView *view;
    QSortFilterProxyModel *proxyModel;

    QLineEdit *findEdit;
    QString _name;

};

