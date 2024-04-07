#include "mainwindow.h"
#include "userlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    userLogin login;
    login.show();

    return a.exec();
}
