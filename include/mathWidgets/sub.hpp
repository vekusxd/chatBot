#include <QWidget>
#include <QLCDNumber>
#include <QSpinBox>
#include <QPushButton>

class SubWidget : public QWidget{
    Q_OBJECT

public:
    explicit SubWidget(QWidget *parent = nullptr);

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
