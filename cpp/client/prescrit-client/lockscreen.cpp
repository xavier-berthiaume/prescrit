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
