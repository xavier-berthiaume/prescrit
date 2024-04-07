#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // Before starting any windows, connect to the server

    MainWindow w;
    w.show();

    return a.exec();
}
