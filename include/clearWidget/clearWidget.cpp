#include "clearWidget.hpp"

#include <QVBoxLayout>

ClearWidget::ClearWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    clearDialog = new ClearDialog;
    mainLayout->addWidget(clearDialog);

    connect(clearDialog, &ClearDialog::accepted, this, &ClearWidget::onClearDialogAccepted);
    connect(clearDialog, &ClearDialog::rejected, this, &ClearWidget::onClearDialogRejected);
}

ClearDialog *ClearWidget::getClearDialog() const
{
    return clearDialog;
}

void ClearWidget::onClearDialogAccepted()
{
    emit clearText();
}

void ClearWidget::onClearDialogRejected()
{
    emit saveText();
}
