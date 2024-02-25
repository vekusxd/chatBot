#include "historyWidget.hpp"

#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <qfile.h>
#include <qdir.h>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QRegularExpression>


HistoryWidget::HistoryWidget(const QString& name, QWidget *parent)
    : _name(name), QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    model = new HistoryModel(_name);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    view = new QTableView;

    view->setModel(proxyModel);
    view->setSortingEnabled(true);

    findEdit = new QLineEdit;
    findEdit->setPlaceholderText("Фильтр команды");

    mainLayout->addWidget(view);
    mainLayout->addWidget(findEdit);

    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    resize(300, 400);

    connect(findEdit, &QLineEdit::textChanged, this, &HistoryWidget::onTextChanged);

}

void HistoryWidget::addObject(const QString& command, const QString &time)
{
    model->appendObject(HistoryObject(command, time));
}


void HistoryWidget::onTextChanged()
{
    if(!findEdit->text().isEmpty()){
        proxyModel->setFilterRegularExpression(QRegularExpression(findEdit->text() + "*", QRegularExpression::CaseInsensitiveOption));
    }

}



