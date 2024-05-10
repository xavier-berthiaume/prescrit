#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lockscreen = new LockScreen(this);
    lock();

    initializeStatusBar();
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

    QTimer *connectionCheckTimer = new QTimer(this);
    connectionCheckTimer->setInterval(5000);
    connectionCheckTimer->start();
    connect(connectionCheckTimer, &QTimer::timeout, this, &MainWindow::updateConnectionLabel);

    statusBar()->showMessage("Disconnected");
}

void MainWindow::updateConnectionLabel()
{

    if(Client::getInstance() == nullptr)
        return;

    qDebug() << "Checking connection status";
    if(Client::getInstance()->checkConnectionStatus())
    {
        qDebug() << "Connection is established";
        statusBar()->showMessage("Connected");
    } else {

        qDebug() << "Connection is not established";
        statusBar()->showMessage("Disconnected");
    }
}
