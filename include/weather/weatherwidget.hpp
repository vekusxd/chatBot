#include <QWidget>
#include <QTableView>
#include <QPushButton>

#include "weathertablemodel.hpp"

class WeatherWidget : public QWidget{
public:
    explicit WeatherWidget(QWidget *parent = nullptr);

private:
    WeatherModel *model;
    QTableView *view;

    QLineEdit *cityEdit;
    QPushButton *sendButton;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};
