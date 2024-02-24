#pragma once

#include <QValidator>

class CityValidator : public QValidator{
    Q_OBJECT
public:
    explicit CityValidator(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString &str, int &idk) const override;
};
