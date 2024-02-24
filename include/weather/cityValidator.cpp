#include "cityValidator.hpp"


CityValidator::CityValidator(QObject *parent)
    : QValidator(parent)
{

}

QValidator::State CityValidator::validate(QString & str, int &idk) const
{
    if(str.contains(QRegularExpression("[^А-Яа-я]"))){
        return Invalid;
    }
    return Acceptable;
}
