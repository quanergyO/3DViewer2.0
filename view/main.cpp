#include "mainwindow.h"
#include "../controller.h"
#include <QApplication>
#include <clocale>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    setlocale(LC_NUMERIC,"C");
    s21::Facade facade;
    s21::Controller& controller = s21::Controller::getInstance(facade);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
