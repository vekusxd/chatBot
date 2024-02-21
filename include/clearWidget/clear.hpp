#pragma once

#include <QDialog>
#include <QPushButton>

class ClearDialog : public QWidget{
    Q_OBJECT

public:
    explicit ClearDialog(QWidget *parent = nullptr);

signals:
    void accepted();
    void rejected();

private:
    QPushButton *acceptButton;
    QPushButton *rejectButton;

private slots:
    void onAcceptPressed();
    void onRejectPressed();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
