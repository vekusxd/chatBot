#include <QWidget>
#include <QLCDNumber>
#include <QSpinBox>
#include <QPushButton>

class MultWidget : public QWidget{
    Q_OBJECT

public:
    explicit MultWidget(QWidget *parent = nullptr);

public slots:
    void onProccessButtonClicked();

private:
    QPushButton *proccessButton;
    QLCDNumber *display;

    QSpinBox *firstNumber;
    QSpinBox *secondNumber ;


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
