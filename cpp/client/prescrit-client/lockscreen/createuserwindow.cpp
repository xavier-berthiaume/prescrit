#include "createuserwindow.h"
#include "ui_createuserwindow.h"

createUserWindow::createUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUserWindow)
{
    ui->setupUi(this);

    setWindowTitle("Create a New User");
    findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(false);
}

createUserWindow::~createUserWindow()
{
    delete ui;
}

bool createUserWindow::checkAllFieldsComplete()
{

    if(findChild<QLineEdit *>("fNameEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("lNameEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("uNameEdit")->text() == "")
        return false;
    if(findChild<QLineEdit *>("pEdit")->text() == "")
        return false;

    return true;
}

void createUserWindow::toggleOkButton()
{

    bool allEditsValid = fNameOk && lNameOk && uNameOk && pOk;

    if(checkAllFieldsComplete() && allEditsValid) {
        findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

bool createUserWindow::validateName(const QString &name)
{

    if(name.length() > 64 || name.length() == 0)
        return false;

    for(const QChar &ch : name) {
       if(!ch.isLetter())
           return false;
    }

    return true;
}

void createUserWindow::on_fNameEdit_textChanged(const QString &arg1)
{

    // Do some primary checks
    if(validateName(arg1)) {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("background-color: green;");
        fNameOk = true;
    } else if (arg1 == "") {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("");
        fNameOk = false;
    } else {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("background-color: red;");
        fNameOk = false;
    }

    toggleOkButton();
}

void createUserWindow::on_lNameEdit_textChanged(const QString &arg1)
{

    // Do some primary checks
    if(validateName(arg1)) {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("background-color: green;");
        lNameOk = true;
    } else if (arg1 == "") {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("");
        lNameOk = false;
    } else {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("background-color: red;");
        lNameOk = false;
    }

    toggleOkButton();
}

// Eventually change this implementation so that you have a timer that goes off 1 second
// after the user stops typing, and that's when you check if the username is available
// This will avoid unnecessary requests to the server
void createUserWindow::on_uNameEdit_textChanged(const QString &arg1)
{

    // When the user enters text here send it to the server, make sure
    // that it isn't already taken, change the background-color
    // depending on availability
    if(Client::getInstance()->checkUsernameAvailable(arg1)) {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: green;");
        uNameOk = true;
    } else if (arg1 == "") {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("");
        uNameOk = false;
    } else {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: red;");
        uNameOk = false;
    }

    toggleOkButton();
}

void createUserWindow::on_pEdit_textChanged(const QString &arg1)
{

    pOk = true;

    toggleOkButton();
}
