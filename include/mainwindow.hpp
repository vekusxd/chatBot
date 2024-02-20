#pragma once

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QShortcut>
#include <QStatusBar>
#include <QListView>

#include "helpcommandswidget.hpp"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, const QString& name = "неизвестен");

private:
    QPushButton *helpButton;
    QPushButton *sendButton;
    QLineEdit *messageEdit;
    QTextEdit *resultDisplay;
    QString userName;

    QStringList commands;

    QStatusBar *nameStatus;

    QString commandsToSave;

    HelpCommandsWidget *commandsWidget;

private:
    QString processCommand(const QString& command);
    void saveHistory();

public slots:
    void onSendButtonClicked();
    void onHelpButtonClicked();
    void onHelpCommandDoubleClicked(const QString& command);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
