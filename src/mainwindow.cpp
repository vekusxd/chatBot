#include "../include/mainwindow.hpp"
#include <QCompleter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget;

    setWindowIcon(QIcon(":/appIcon.png"));

    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    resultDisplay = new QTextEdit;
    resultDisplay->setReadOnly(true);

    mainLayout->addWidget(resultDisplay);

    QHBoxLayout *sendLayout = new QHBoxLayout;

    messageEdit = new QLineEdit;
    messageEdit->setPlaceholderText("Введите команду");

    sendButton = new QPushButton;
    sendButton->setIcon(QIcon(":/sendIcon.png"));
    sendButton->setToolTip("Отправить");

    sendLayout->addWidget(messageEdit, 8);
    sendLayout->addWidget(sendButton, 1);

    mainLayout->addLayout(sendLayout);

    commands << "/погода" << "/валюта" << "/привет";

    QCompleter *completer = new QCompleter(commands, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    messageEdit->setCompleter(completer);

    resize(590, 460);
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
}

void MainWindow::onSendButtonClicked()
{
    if(messageEdit->text().isEmpty()){
        return;
    }
    resultDisplay->setText(resultDisplay->toPlainText() + QString("\n- %1").arg(messageEdit->text()));
    messageEdit->clear();
}
