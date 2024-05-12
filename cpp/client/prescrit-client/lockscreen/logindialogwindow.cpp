#include "logindialogwindow.h"
#include "ui_logindialogwindow.h"

LoginDialogWindow::LoginDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialogWindow)
{
    ui->setupUi(this);
}

LoginDialogWindow::~LoginDialogWindow()
{
    delete ui;
}
