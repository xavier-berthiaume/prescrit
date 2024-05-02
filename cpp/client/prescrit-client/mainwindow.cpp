#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lockscreen = new LockScreen(this);
    lock();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lock()
{
    setCentralWidget(lockscreen);
}
