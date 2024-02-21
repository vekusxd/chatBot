#pragma once

#include <QObject>
#include <QWidget>
#include <QIcon>

class CommandItem{

public:
    CommandItem(const QString& title, const QString& toolTipText, QWidget* widget, QIcon icon);

public:
    QString getTitle() const;
    QString getToolTipText() const;
    QIcon getIcon() const;
    QWidget* getWidget() const;

    void processCommand();

private:
    QString _title;
    QString _toolTipText;
    QWidget *_widget;
    QIcon _icon;
};
