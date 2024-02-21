#include "clear.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QMessageBox>
#include <QKeyEvent>

ClearDialog::ClearDialog(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *infoLabel = new QLabel("Вы уверены?");
    infoLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(infoLabel);

    acceptButton = new QPushButton("&Да");
    rejectButton = new QPushButton("&Нет");

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(acceptButton);
    buttonsLayout->addWidget(rejectButton);

    mainLayout->addLayout(buttonsLayout);

    connect(acceptButton, &QPushButton::clicked, this, &ClearDialog::accepted);
    connect(rejectButton, &QPushButton::clicked, this, &ClearDialog::onRejectPressed);
}

void ClearDialog::onAcceptPressed()
{
    emit accepted();
}

void ClearDialog::onRejectPressed()
{
    emit rejected();
}

void ClearDialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Return:
        acceptButton->click();
        return;
    case Qt::Key_Escape:
        rejectButton->click();
        return;
    }
}
