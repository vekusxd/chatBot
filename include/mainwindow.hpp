#pragma once

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QPushButton *sendButton;
    QLineEdit *messageEdit;
    QTextEdit *resultDisplay;

public slots:
    void onSendButtonClicked();
};
