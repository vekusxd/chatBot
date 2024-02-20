#include "../include/mainwindow.hpp"
#include <QCompleter>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QTime>
#include <QDateTime>
#include <QLabel>
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QRegularExpression>

#include "../include/commandmodel.hpp"

MainWindow::MainWindow(QWidget *parent, const QString& name)
    : QMainWindow(parent), userName(name)
{
    QWidget *centralWidget = new QWidget;

    setWindowIcon(QIcon(":/appIcon.png"));

    setCentralWidget(centralWidget);

    nameStatus = new QStatusBar;

    if(name.isEmpty()){
        nameStatus->addWidget(new QLabel("Неизвестный пользователь"));
    }
    else{
        nameStatus->addWidget(new QLabel(QString("Текущий пользователь: %1").arg(name)));
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    resultDisplay = new QTextEdit;
    resultDisplay->setReadOnly(true);

    mainLayout->addWidget(resultDisplay);

    QHBoxLayout *sendLayout = new QHBoxLayout;

    messageEdit = new QLineEdit;
    messageEdit->setPlaceholderText("Введите команду");

    helpButton = new QPushButton;
    helpButton->setIcon(QIcon(":/helpIcon.png"));
    helpButton->setToolTip("Помощь");

    sendButton = new QPushButton;

    sendButton->setIcon(QIcon(":/sendIcon.png"));
    sendButton->setToolTip("Отправить");

    sendLayout->addWidget(helpButton, 1);
    sendLayout->addWidget(messageEdit, 8);
    sendLayout->addWidget(sendButton, 1);

    mainLayout->addLayout(sendLayout);

    commandsWidget = new HelpCommandsWidget;

    commands << "/погода" << "/валюта" << "/привет";

    QCompleter *completer = new QCompleter;
    completer->setModel(commandsWidget->view->model());
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionRole(Qt::DisplayRole);
    messageEdit->setCompleter(completer);


    resize(590, 460);

    setStatusBar(nameStatus);

    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    connect(helpButton, &QPushButton::clicked, this, &MainWindow::onHelpButtonClicked);
    connect(commandsWidget, &HelpCommandsWidget::sendClickedCommand, this, &MainWindow::onHelpCommandDoubleClicked);
}

QString MainWindow::processCommand(const QString &command)
{
    QRegularExpression helloPattern("\\s*\\w*здрав\\w*\\s*",  QRegularExpression::CaseInsensitiveOption);
    if(command.contains(helloPattern)){
        return "- Добрый день!";
    }
    return "Неизвестная команда";
}

void MainWindow::saveHistory()
{

    QString path(QDir::home().absolutePath() + "/Documents/simpleChatBot/");
    QDir dir;

    if(!dir.exists(path)){
        dir.mkpath(path);
    }

    QFile file;

    if(userName.isEmpty()){
        file.setFileName(path + "unknown.txt");
    }
    else{
        file.setFileName(path + userName + ".txt");
    }

    file.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream stream(&file);

    stream << commandsToSave;

    file.close();
}

void MainWindow::onSendButtonClicked()
{
    if(messageEdit->text().isEmpty()){
        return;
    }
    resultDisplay->append(QString("\n- %1").arg(messageEdit->text()));
    resultDisplay->moveCursor(QTextCursor::End);
    resultDisplay->append(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "\n");

    commandsToSave += messageEdit->text() + "\t" + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "\n";

    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    if(commandModel->containsCommand(messageEdit->text())){
        auto item  = commandModel->getCommandItem(messageEdit->text());
        item.processCommand();
    }
    else{
        resultDisplay->append(processCommand(messageEdit->text()));
    }
    messageEdit->clear();
}

void MainWindow::onHelpButtonClicked()
{
    commandsWidget->show();
}

void MainWindow::onHelpCommandDoubleClicked(const QString &command)
{
    commandsWidget->hide();
    messageEdit->setText(command);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return){
        sendButton->click();
        messageEdit->setFocus();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox message;
    message.setIcon(QMessageBox::Question);
    message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    message.setInformativeText("Вы уверены что хотите выйти?");
    switch(message.exec()){
    case QMessageBox::Yes:
        saveHistory();
        event->accept();
        break;
    default:
        event->ignore();
        break;
    }
}
