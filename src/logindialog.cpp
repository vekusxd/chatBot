#include "../include/logindialog.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "../include/namevalidator.hpp"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *greetingLabel = new QLabel("Добро пожаловать");
    greetingLabel->setFont(QFont("Times", 18, QFont::Bold));
    greetingLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    mainLayout->addWidget(greetingLabel);

    QHBoxLayout *forNameLayout = new QHBoxLayout;

    QLabel *name = new QLabel("Введите ваше имя: ");


    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("имя");
    nameEdit->setValidator(new NameValidator);


    forNameLayout->addWidget(name);
    forNameLayout->addWidget(nameEdit);

    mainLayout->addLayout(forNameLayout);

    loginPicture = new QLabel;
    loginPicture->setPixmap(QPixmap(":/welcome.jpg"));

    mainLayout->addWidget(loginPicture);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QPushButton *acceptButton = new QPushButton("&Принять");
    QPushButton *rejectButton = new QPushButton("&Выйти");

    buttonsLayout->addWidget(acceptButton);
    buttonsLayout->addWidget(rejectButton);

    mainLayout->addLayout(buttonsLayout);

    connect(acceptButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(rejectButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString LoginDialog::getName() const
{
    return nameEdit->text();
}


