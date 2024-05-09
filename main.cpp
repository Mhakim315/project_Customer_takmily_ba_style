#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Form");
    //w.setStyleSheet("background-image : url('C:/Users/ModernSystem/Documents/tamrin_asly/image.jpg');");

    w.show();
    return a.exec();
}
