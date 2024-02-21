#include "../include/commanditem.hpp"


CommandItem::CommandItem(const QString &title, const QString &toolTipText, QWidget *widget, QIcon icon)
    : _title(title), _toolTipText(toolTipText), _widget(widget), _icon(icon)
{ }

QString CommandItem::getTitle() const
{
    return _title;
}

QString CommandItem::getToolTipText() const
{
    return _toolTipText;
}

QIcon CommandItem::getIcon() const
{
    return _icon;
}

QWidget *CommandItem::getWidget() const
{
    return _widget;
}

void CommandItem::processCommand()
{
    _widget->show();
}


