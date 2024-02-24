#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QCompleter>
#include <QNetworkAccessManager>

#include "weathertablemodel.hpp"

class WeatherWidget : public QWidget{
public:
    explicit WeatherWidget(QWidget *parent = nullptr);

private:
    WeatherModel *model;
    QTableView *view;

    QLineEdit *cityEdit;
    QPushButton *sendButton;

    QStringList cities;

    QCompleter *completer;

    QNetworkAccessManager *manager;


public slots:
    void onSendButtonClicked();
    void onReplyFinished(QNetworkReply *reply);
private:
    QStringList getCities();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
