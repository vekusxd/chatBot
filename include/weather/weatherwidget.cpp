#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QResizeEvent>

#include "weatherwidget.hpp"
#include "cityValidator.hpp"

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainlayout  = new QVBoxLayout(this);

    QHBoxLayout *findLayout = new QHBoxLayout;

    cityEdit = new QLineEdit;
    cityEdit->setPlaceholderText("Город");
    cityEdit->setValidator(new CityValidator);

    sendButton = new QPushButton;
    sendButton->setIcon(QIcon(":/findIcon.png"));

    findLayout->addWidget(cityEdit, 8);
    findLayout->addWidget(sendButton, 1);

    mainlayout->addLayout(findLayout);

    model = new WeatherModel;
    view = new QTableView;

    view->setModel(model);
    mainlayout->addWidget(view);

    resize(726, 400);
    setFixedWidth(726);

}

void WeatherWidget::resizeEvent(QResizeEvent *event)
{
    //qDebug() << event->size();
}
