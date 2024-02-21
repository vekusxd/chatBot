#include "clear.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QMessageBox>

ClearDialog::ClearDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *infoLabel = new QLabel("Вы уверены?");
    infoLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(infoLabel);

    QPushButton *acceptButton = new QPushButton("&Да");
    QPushButton *rejectButton = new QPushButton("&Нет");

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(acceptButton);
    buttonsLayout->addWidget(rejectButton);

    mainLayout->addLayout(buttonsLayout);

    connect(acceptButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(rejectButton, &QPushButton::clicked, this, &QDialog::reject);
}
