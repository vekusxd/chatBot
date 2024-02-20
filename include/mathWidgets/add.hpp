#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>

class AddWidget : public QWidget{

    Q_OBJECT

public:
    explicit AddWidget(QWidget *parent = nullptr);

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
