#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#pragma once

class LoginDialog : public QDialog{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private:
    QLabel *loginPicture;
    QLineEdit *nameEdit;
    QPushButton *acceptButton;

public:
    QString getName() const;


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
