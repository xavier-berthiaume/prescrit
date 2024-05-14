#include "createuserwindow.h"
#include "ui_createuserwindow.h"

createUserWindow::createUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUserWindow)
{

    ui->setupUi(this);

    setWindowTitle("Create a New User");
    findChild<QDialogButtonBox *>("buttonBox")->button(QDialogButtonBox::Ok)->setEnabled(false);
    findChild<QLabel *>("statusLabel")->setText("");
    findChild<QLabel *>("statusLabel")->hide();

    noEditTimer = new QTimer();
    noEditTimer->setSingleShot(true);
    connect(noEditTimer, &QTimer::timeout, this, &createUserWindow::handle_uName_validation);
    connect(findChild<QLineEdit *>("uNameEdit"), &QLineEdit::textChanged, this, &createUserWindow::startTimer);
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

void createUserWindow::displayStatusLabel(const QString &statusmessage)
{

        QLabel *statuslabel = findChild<QLabel *>("statusLabel");
        statuslabel->setStyleSheet("color: red;");
        statuslabel->setText(statusmessage);
        statuslabel->show();
}

void createUserWindow::hideStatusLabel(const QString &statusToHide)
{

        QLabel *statuslabel = findChild<QLabel *>("statusLabel");
        if(statuslabel->text() == statusToHide)
            statuslabel->hide();
}

void createUserWindow::on_fNameEdit_textChanged(const QString &arg1)
{

    // Do some primary checks
    if(validateName(arg1)) {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("background-color: green;");
        fNameOk = true;

        hideStatusLabel("The first name isn't valid");
    } else if (arg1 == "") {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("");
        fNameOk = false;
    } else {
        findChild<QLineEdit *>("fNameEdit")->setStyleSheet("background-color: red;");
        fNameOk = false;

        displayStatusLabel("The first name isn't valid");
    }

    toggleOkButton();
}

void createUserWindow::on_lNameEdit_textChanged(const QString &arg1)
{

    // Do some primary checks
    if(validateName(arg1)) {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("background-color: green;");
        lNameOk = true;

        hideStatusLabel("The last name isn't valid");
    } else if (arg1 == "") {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("");
        lNameOk = false;
    } else {
        findChild<QLineEdit *>("lNameEdit")->setStyleSheet("background-color: red;");
        lNameOk = false;
        displayStatusLabel("The last name isn't valid");
    }

    toggleOkButton();
}

// Eventually change this implementation so that you have a timer that goes off 1 second
// after the user stops typing, and that's when you check if the username is available
// This will avoid unnecessary requests to the server
void createUserWindow::on_uNameEdit_textChanged(const QString &arg1)
{

    findChild<QLineEdit *>("uNameEdit")->setStyleSheet("");

    toggleOkButton();
}

void createUserWindow::on_pEdit_textChanged(const QString &arg1)
{

    pOk = true;

    toggleOkButton();
}

void createUserWindow::handle_uName_validation()
{

    QLineEdit *uName = findChild<QLineEdit *>("uNameEdit");

    // Make sure the client is connected
    if(!Client::getInstance()->checkConnectionStatus()) {
        uName->setStyleSheet("background-color: red;");
        displayStatusLabel("There is no connection to the server currently");
        uNameOk = false;
        return;
    }

    // When the user enters text here send it to the server, make sure
    // that it isn't already taken, change the background-color
    // depending on availability
    if (uName->text() == "") {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("");
        uNameOk = false;
    } else if(Client::getInstance()->checkUsernameAvailable(uName->text())) {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: green;");
        uNameOk = true;

        hideStatusLabel("The username is already taken");
        hideStatusLabel("There is no connection to the server currently");
    }  else {
        findChild<QLineEdit *>("uNameEdit")->setStyleSheet("background-color: red;");
        displayStatusLabel("The username is already taken");
        uNameOk = false;
    }
}

void createUserWindow::startTimer()
{

    noEditTimer->start(300);
}

void createUserWindow::on_buttonBox_accepted()
{

    bool response = Client::getInstance()->createUser(
        findChild<QLineEdit *>("fNameEdit")->text(),
        findChild<QLineEdit *>("lNameEdit")->text(),
        findChild<QLineEdit *>("uNameEdit")->text(),
        findChild<QLineEdit *>("pEdit")->text()
    );

    if(response) {
    // User creation was successful

    } else {
    // User creation wasn't successful

    }
}

