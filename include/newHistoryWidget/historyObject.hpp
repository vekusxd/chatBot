#pragma once

#include <QString>

class HistoryObject{
public:
    HistoryObject();
    HistoryObject(const QString& command, const QString& time);

public:
    QString getCommand() const;
    QString getTime() const;
private:
    QString _command;
    QString _time;
};
