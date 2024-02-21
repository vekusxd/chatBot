#include "clearWidget.hpp"

#include <QVBoxLayout>

ClearWidget::ClearWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    clearDialog = new ClearDialog;
    mainLayout->addWidget(clearDialog);

    connect(clearDialog, &ClearDialog::accepted, this, &ClearWidget::onClearDialogAccepted);
}

ClearDialog *ClearWidget::getClearDialog() const
{
    return clearDialog;
}

void ClearWidget::onClearDialogAccepted()
{
    emit clearText();
}
