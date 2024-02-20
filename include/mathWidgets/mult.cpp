#include "mult.hpp"

#include <QHBoxLayout>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QLabel>

MultWidget::MultWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    firstNumber = new QSpinBox;
    secondNumber = new QSpinBox;
    firstNumber->setValue(0);
    secondNumber->setValue(0);
    firstNumber->setRange(-1000000, 100000);
    secondNumber->setRange(-1000000, 100000);
    QLabel *operatorLabel = new QLabel("*");
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
    connect(proccessButton, &QPushButton::clicked, this, &MultWidget::onProccessButtonClicked);
}

void MultWidget::onProccessButtonClicked()
{
    display->display(QString::number(firstNumber->value() * secondNumber->value()));
}

void MultWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Equal || event->key() == Qt::Key_Plus){
        proccessButton->click();
    }
}
