#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lockscreen/lockscreen.h"
#include "rpcclient.h"

#include <QDebug>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void lock();
    void unlock();

private:
    Ui::MainWindow *ui;

    LockScreen *lockscreen;

    void initializeStatusBar();

    void updateConnectionLabel();
};
#endif // MAINWINDOW_H
