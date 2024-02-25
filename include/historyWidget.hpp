#pragma once

#include <QLabel>
#include <QTextEdit>
#include <QWidget>


class HistoryWidget : public QWidget{
    Q_OBJECT

public:
    explicit HistoryWidget(const QString& name, QWidget *parent = nullptr);
    void appendHistory(const QString& toAdd);

    void loadFromFile(const QString &history);

private:
    QString _name;
    QString showString;
    QTextEdit *showEdit;
    QLabel *nameLabel;
};
