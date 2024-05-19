#include "lockscreen.h"
#include "ui_lockscreen.h"

LockScreen::LockScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockScreen)
{
    ui->setupUi(this);

    // this->setWindowTitle("Locked");
    // this->setWindowModality(Qt::ApplicationModal);
}

LockScreen::~LockScreen()
{
    delete ui;
}

void LockScreen::on_newUserButton_clicked()
{

    createUserWindow *modal = new createUserWindow(this);
    modal->show();
}


void LockScreen::on_loginButton_clicked()
{

    LoginDialogWindow *modal = new LoginDialogWindow(this);
    modal->show();
}

