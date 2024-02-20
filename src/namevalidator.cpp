#include "../include/namevalidator.hpp"
#include <QRegularExpression>

NameValidator::NameValidator(QObject *parent)
    : QValidator(parent)
{}

QValidator::State NameValidator::validate(QString &str, int &idk) const
{
    if(str.contains(QRegularExpression("[A-Za-z0-9]"))){
        return Invalid;
    }
    return Acceptable;
}
