#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#pragma once

class LoginDialog : public QDialog{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private:
    QLabel *loginPicture;
    QLineEdit *nameEdit;

public:
    QString getName() const;

};
