#pragma once

#include "clear.hpp"

#include <QWidget>

class ClearWidget : public QWidget{
    Q_OBJECT

public:
    explicit ClearWidget(QWidget *parent = nullptr);
    ClearDialog* getClearDialog() const;

private:
    ClearDialog *clearDialog;
signals:
    void clearText();

private slots:
    void onClearDialogAccepted();
};
