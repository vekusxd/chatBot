#include <QApplication>
#include <QStatusBar>
#include <QMessageBox>
#include "../include/mainwindow.hpp"
#include "../include/logindialog.hpp"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    LoginDialog dialog;

    if(dialog.exec() == QDialog::Accepted){
        MainWindow widget;
        QStatusBar statusBar;
        if(dialog.getName().isEmpty()){
            QMessageBox info;
            info.setInformativeText("История не будет сохранена!");
            info.setDefaultButton(QMessageBox::Ok);
            info.setIcon(QMessageBox::Warning);
            info.exec();
            statusBar.addWidget(new QLabel("Анонимный пользователь"));
        }
        else{
            statusBar.addWidget(new QLabel(QString("Текущий пользователь: %1").arg(dialog.getName())));
        }
        widget.setStatusBar(&statusBar);
        widget.show();
        return app.exec();
    }
    else{
        QApplication::exit();
    }
}
