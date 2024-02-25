#include "../include/historyWidget.hpp"
#include <QFile>

#include <QDir>
#include <QVBoxLayout>

HistoryWidget::HistoryWidget(const QString &name, QWidget *parent)
    : _name(name)
    , QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    //loadFromFile(_name);
    if(!name.isEmpty()){
        nameLabel = new QLabel(QString("Текущий пользователь: %1").arg(_name));
    }
    else{
        nameLabel = new QLabel("Неизвестный пользователь");
    }

    mainLayout->addWidget(nameLabel, Qt::AlignVCenter);

    showEdit = new QTextEdit;
    showEdit->setReadOnly(true);

    mainLayout->addWidget(showEdit);
    resize(300, 200);
}

void HistoryWidget::appendHistory(const QString &toAdd)
{
    showString += toAdd;
    showEdit->setPlainText(showString);
}

void HistoryWidget::loadFromFile(const QString &history)
{
    showString += history;
    showEdit->setPlainText(showString);
}

