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
#include <QToolBar>

#include "../include/commandmodel.hpp"
#include "../include/clearWidget/clearWidget.hpp"
#include "../include/syntaxhighlighter.hpp"

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

    historyWidget = new HistoryWidget(name);
    //historyWidget->loadFromFile(loadHistory());

    SyntaxHiglighter *higlighter = new SyntaxHiglighter(resultDisplay->document());

    toolBar = new QToolBar;
    toolBar->addAction(QPixmap(":/history.png"), "История", this, &MainWindow::showHistory);
    toolBar->addAction(QPixmap(":/clear.png"), "Очистить", this, &MainWindow::clear);
    toolBar->addAction(QPixmap(":/weatherIcon.png"), "Прогноз погоды", this, &MainWindow::showWeather);
    addToolBar(Qt::TopToolBarArea, toolBar);


    mainLayout->addWidget(resultDisplay);

    QHBoxLayout *sendLayout = new QHBoxLayout;

    messageEdit = new QLineEdit;
    messageEdit->setPlaceholderText("Введите команду");



    helpButton = new QPushButton;
    helpButton->setIcon(QIcon(":/helpIcon.png"));
    helpButton->setToolTip("Помощь");

    sendButton = new QPushButton;

    sendButton->setIcon(QIcon(":/newSend.png"));
    sendButton->setToolTip("Отправить");

    sendLayout->addWidget(helpButton, 1);
    sendLayout->addWidget(messageEdit, 8);
    sendLayout->addWidget(sendButton, 1);

    mainLayout->addLayout(sendLayout);

    commandsWidget = new HelpCommandsWidget;

    completer = new QCompleter;
    completer->setModel(commandsWidget->view->model());
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionRole(Qt::DisplayRole);
    completer->setWrapAround(false);
    messageEdit->setCompleter(completer);


    resize(590, 460);

    setStatusBar(nameStatus);

    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    connect(helpButton, &QPushButton::clicked, this, &MainWindow::onHelpButtonClicked);
    connect(commandsWidget, &HelpCommandsWidget::sendClickedCommand, this, &MainWindow::onHelpCommandDoubleClicked);

    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    auto item = commandModel->getCommandItem("/очистить");
    ClearWidget *clear = static_cast<ClearWidget*>(item.getWidget());
    connect(clear, &ClearWidget::clearText, this, &MainWindow::onClearTextSignal);
    connect(clear,&ClearWidget::saveText, this,  &MainWindow::onSaveTextSignal);
}

QString MainWindow::processCommand(const QString &command)
{
    static QList<QRegularExpression> Hellopatterns;
    static QList<QRegularExpression> timePatterns;
    Hellopatterns << QRegularExpression("\\s*\\w*здрав\\w*\\s*",  QRegularExpression::CaseInsensitiveOption);
    Hellopatterns << QRegularExpression("\\s*\\w*прив\\w*\\s*", QRegularExpression::CaseInsensitiveOption);
    Hellopatterns << QRegularExpression("\\s*\\w*шалом\\w*\\s*", QRegularExpression::CaseInsensitiveOption);
    Hellopatterns << QRegularExpression("\\s*\\w*ку\\w*\\s*", QRegularExpression::CaseInsensitiveOption);

    timePatterns << QRegularExpression("\\s*\\w*час\\w*\\s*", QRegularExpression::CaseInsensitiveOption);
    timePatterns << QRegularExpression("\\s*\\w*время\\w*\\s*", QRegularExpression::CaseInsensitiveOption);
    timePatterns << QRegularExpression("\\s*\\w*времени\\w*\\s*", QRegularExpression::CaseInsensitiveOption);

    for(const auto& i : Hellopatterns){
        if(command.contains(i)){
            return "- Добрый день!";
        }
    }

    for(const auto& i : timePatterns){
        if(command.contains(i)){
            return QString("Сейчас: %1").arg(QTime::currentTime().toString());
        }
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

QString MainWindow::loadHistory()
{
    QFile file;

    QString path(QDir::home().absolutePath() + "/Documents/simpleChatBot/");
    QDir dir;

    if(!dir.exists(path)){
        dir.mkpath(path);
    }

    if(userName.isEmpty()){
        file.setFileName(path + "unknown.txt");
    }
    else{
        file.setFileName(path + userName + ".txt");
    }

    if(!file.open(QIODevice::ReadOnly)){
        return "";
    }

    return file.readAll();
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
    //historyWidget->appendHistory(messageEdit->text() + "\t" + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "\n");
    historyWidget->addObject(messageEdit->text(), QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

    if(messageEdit->text() == "/история"){
        historyWidget->show();
        messageEdit->clear();
        return;
    }

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

void MainWindow::onClearTextSignal()
{
    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    auto item = commandModel->getCommandItem("/очистить");
    ClearWidget *clear = static_cast<ClearWidget*>(item.getWidget());
    resultDisplay->clear();
    clear->hide();
}

void MainWindow::onSaveTextSignal()
{
    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    auto item = commandModel->getCommandItem("/очистить");
    ClearWidget *clear = static_cast<ClearWidget*>(item.getWidget());
    clear->hide();
}

void MainWindow::showHistory()
{
    historyWidget->show();

}

void MainWindow::clear()
{
    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    auto item  = commandModel->getCommandItem("/очистить");
    item.processCommand();
}

void MainWindow::showWeather()
{
    CommandModel* commandModel = static_cast<CommandModel*>(commandsWidget->view->model());
    auto item  = commandModel->getCommandItem("/погода");
    item.processCommand();
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
