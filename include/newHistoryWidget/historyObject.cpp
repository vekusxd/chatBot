#include "historyObject.hpp"

HistoryObject::HistoryObject()
    : _command{"unknown"}
    , _time{"unkown"}
{
}

HistoryObject::HistoryObject(const QString &command, const QString &time)
    : _command(command)
    , _time(time)
{
}

QString HistoryObject::getCommand() const
{
    return _command;
}

QString HistoryObject::getTime() const
{
    return _time;
}
