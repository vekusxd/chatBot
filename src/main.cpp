#include <QApplication>
#include <QStatusBar>
#include <QMessageBox>
#include "../include/mainwindow.hpp"
#include "../include/logindialog.hpp"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    LoginDialog dialog;

    if(dialog.exec() == QDialog::Accepted){
        MainWindow widget(nullptr, dialog.getName());
        if(dialog.getName().isEmpty()){
            MainWindow widget;
            QMessageBox info;
            info.setInformativeText("История будет сохранена в общий файл!");
            info.setDefaultButton(QMessageBox::Ok);
            info.setIcon(QMessageBox::Warning);
            info.exec();
        }
        widget.show();
        return app.exec();
    }
    else{
        QApplication::exit();
    }
}
