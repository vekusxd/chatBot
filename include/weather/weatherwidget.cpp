#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QResizeEvent>
#include <QFile>
#include <QCompleter>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QSortFilterProxyModel>
#include <QHeaderView>

#include "weatherwidget.hpp"
#include "cityValidator.hpp"

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget(parent)
{
    manager = new QNetworkAccessManager(this);

    QVBoxLayout *mainlayout  = new QVBoxLayout(this);

    QHBoxLayout *findLayout = new QHBoxLayout;

    cityEdit = new QLineEdit;
    cityEdit->setPlaceholderText("Город");
    cityEdit->setValidator(new CityValidator);

    cities = getCities();
    completer = new QCompleter(cities, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    cityEdit->setCompleter(completer);

    sendButton = new QPushButton;
    sendButton->setIcon(QIcon(":/findIcon.png"));

    findLayout->addWidget(cityEdit, 8);
    findLayout->addWidget(sendButton, 1);

    mainlayout->addLayout(findLayout);

    model = new WeatherModel;
    view = new QTableView;

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);


    //view->setModel(model);
    view->setModel(proxyModel);
    view->setSortingEnabled(true);
    mainlayout->addWidget(view);

    resize(780, 400);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(sendButton, &QPushButton::clicked, this, &WeatherWidget::onSendButtonClicked);
    connect(manager, &QNetworkAccessManager::finished, this, &WeatherWidget::onReplyFinished);
}

void WeatherWidget::onSendButtonClicked()
{
    if(cityEdit->text().isEmpty()){
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setInformativeText("Запрос не должен быть пустым!");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }

    manager->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q=" + cityEdit->text() +
     "&lang=ru&units=metric&appid=0f576abcef293d46233d51e95e883ac0")));

    cityEdit->clear();
    cityEdit->setFocus();
}

void WeatherWidget::onReplyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject obj = doc.object();
        model->appendObject(WeatherObject(obj));
    }
    else{
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setInformativeText("Такого города нет!");
        box.setText("Ошибка");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
}

QStringList WeatherWidget::getCities()
{
    QStringList result;
    QFile file(":/cities.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return result;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        result << in.readLine();
    }
    return result;
}

void WeatherWidget::resizeEvent(QResizeEvent *event)
{
    //qDebug() << event->size();
}

void WeatherWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return){
        sendButton->click();
    }
}


