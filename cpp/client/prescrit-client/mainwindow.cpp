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

void MainWindow::unlock()
{

}

void MainWindow::initializeStatusBar()
{

    QLabel *connectionStatus = new QLabel(this);
    connectionStatus->setText("Disconnected");

    QTimer *connectionCheckTimer = new QTimer(connectionStatus);
    connect(connectionCheckTimer, &QTimer::timeout, );
}
