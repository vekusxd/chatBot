#include "div.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>

DivWidget::DivWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    firstNumber = new QSpinBox;
    secondNumber = new QSpinBox;
    firstNumber->setValue(0);
    secondNumber->setValue(0);
    firstNumber->setRange(-1000000, 100000);
    secondNumber->setRange(-1000000, 100000);
    QLabel *operatorLabel = new QLabel("/");
    operatorLabel->setAlignment(Qt::AlignCenter);
    operatorLabel->setFont(QFont("Times", 18, QFont::Bold));

    QHBoxLayout *operatorsLayout = new QHBoxLayout;
    operatorsLayout->addWidget(firstNumber);
    operatorsLayout->addWidget(operatorLabel);
    operatorsLayout->addWidget(secondNumber);

    mainLayout->addLayout(operatorsLayout);

    QHBoxLayout *displayLayout = new QHBoxLayout;

    display = new QLCDNumber;
    display->setSegmentStyle(QLCDNumber::Flat);
    display->setSmallDecimalPoint(true);
    display->display(0);

    proccessButton = new QPushButton;
    proccessButton->setIcon(QIcon(":/равно.png"));

    displayLayout->addWidget(display, 8);
    displayLayout->addWidget(proccessButton, 1);

    mainLayout->addLayout(displayLayout);
    connect(proccessButton, &QPushButton::clicked, this, &DivWidget::onProccessButtonClicked);
}

void DivWidget::onProccessButtonClicked()
{
    if(secondNumber->value() != 0){
        display->display(QString::number(static_cast<double>(firstNumber->value()) / static_cast<double>(secondNumber->value())));
        return;
    }
    QMessageBox warning;
    warning.setIcon(QMessageBox::Critical);
    warning.setInformativeText("Делить на 0 нельзя!");
    warning.exec();
}

void DivWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Equal || event->key() == Qt::Key_Plus){
        proccessButton->click();
    }
}
