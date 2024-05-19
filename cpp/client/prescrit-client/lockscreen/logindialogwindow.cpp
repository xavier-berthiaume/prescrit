#include "logindialogwindow.h"
#include "ui_logindialogwindow.h"

const QString LoginDialogWindow::noUsernameMessage = "User does not exist";

LoginDialogWindow::LoginDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialogWindow)
{

    ui->setupUi(this);

    setWindowTitle("Login User");
    findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(false);
    findChild<QLabel *>("statusLabel")->setText("");
    findChild<QLabel *>("statusLabel")->hide();
}

LoginDialogWindow::~LoginDialogWindow()
{

    delete ui;
}

bool LoginDialogWindow::checkAllFieldsComplete()
{

    if(findChild<QLineEdit *>("uNameEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("pEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("pinEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("confPinEdit")->text() == "")
        return false;

    return true;
}

void LoginDialogWindow::toggleOkButton()
{

    bool allEditsValid = uNameValid && pOk && pinOk && confPinOk;

    if(checkAllFieldsComplete() && allEditsValid) {
        findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void LoginDialogWindow::displayStatusLabel(const QString &statusmessage)
{

    QLabel *statuslabel = findChild<QLabel *>("statusLabel");
    statuslabel->setStyleSheet("color: red;");
    statuslabel->setText(statusmessage);
    statuslabel->show();
}

void LoginDialogWindow::hideStatusLabel(const QString &statusToHide)
{

        QLabel *statuslabel = findChild<QLabel *>("statusLabel");
        if(statuslabel->text() == statusToHide)
            statuslabel->hide();
}

void LoginDialogWindow::on_uNameEdit_editingFinished()
{

    QLineEdit *uName = findChild<QLineEdit *>("uNameEdit");

    // Make sure the client is connected
    if(!Client::getInstance()->checkConnectionStatus()) {
        uName->setStyleSheet("background-color: red;");
        displayStatusLabel("There is no connection to the server currently");
        uNameValid = false;
        return;
    }

    // When the user enters text here send it to the server, make sure
    // that it isn't already taken, change the background-color
    // depending on availability
    if (uName->text() == "") {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("");
        uNameValid = false;

        findChild<QLineEdit *>("pEdit")->setEnabled(false);
    } else if(!Client::getInstance()->checkUsernameAvailable(uName->text())) {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: green;");
        uNameValid = true;

        findChild<QLineEdit *>("pEdit")->setEnabled(true);

        hideStatusLabel(noUsernameMessage);
        hideStatusLabel("There is no connection to the server currently");
    }  else {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: red;");
        displayStatusLabel(noUsernameMessage);
        uNameValid = false;

        findChild<QLineEdit *>("pEdit")->setEnabled(false);
    }
}
