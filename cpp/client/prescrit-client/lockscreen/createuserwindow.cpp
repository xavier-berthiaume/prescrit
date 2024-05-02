#include "createuserwindow.h"
#include "ui_createuserwindow.h"

createUserWindow::createUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUserWindow)
{
    ui->setupUi(this);
}

createUserWindow::~createUserWindow()
{
    delete ui;
}
