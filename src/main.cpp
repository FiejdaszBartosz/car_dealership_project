#include "../include/mainwindow.h"
#include "../include/Vehicle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Vehicle nowyPojazd;
    MainWindow w;
    w.show();
    return a.exec();
}
