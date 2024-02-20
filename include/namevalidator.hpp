#pragma once

#include <QValidator>

class NameValidator : public QValidator{

    Q_OBJECT
public:
    explicit NameValidator(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString & str, int &idk) const override;
};
