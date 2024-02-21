#include "../include/namevalidator.hpp"
#include <QRegularExpression>

NameValidator::NameValidator(QObject *parent)
    : QValidator(parent)
{}

QValidator::State NameValidator::validate(QString &str, int &idk) const
{
    if(str.contains(QRegularExpression("[^А-Яа-я]"))){
        return Invalid;
    }
    return Acceptable;
}
