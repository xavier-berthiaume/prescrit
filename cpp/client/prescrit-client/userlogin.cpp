#include "userlogin.h"
#include "ui_userlogin.h"

#include <prescrit/globals.h>

userLogin::userLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userLogin)
{
    ui->setupUi(this);

    QLineEdit *usernameEdit = findChild<QLineEdit *>("usernameEdit");
    QLineEdit *passEdit = findChild<QLineEdit *>("passwordEdit");
    QLineEdit *pinEdit = findChild<QLineEdit *>("pinEdit");
    QLineEdit *pinConfirmEdit = findChild<QLineEdit *>("pinConfirmEdit");

    QFont font = usernameEdit->font();
    QFontMetrics fontMetrics(font);

    int charWidth = fontMetrics.horizontalAdvance(QLatin1Char('X'));
    int widthForUsernameMaxChars = charWidth * MAXUSERNAMELEGNTH;
    int widthForPassMaxChars = charWidth * MAXPASSWORDLENGTH;
    int widthForPin = charWidth * PINLENGTH;

    usernameEdit->setFixedWidth(widthForUsernameMaxChars);
    usernameEdit->setEnabled(true);

    passEdit->setFixedWidth(widthForPassMaxChars);
    passEdit->setEnabled(false);

    pinEdit->setFixedWidth(widthForPin);
    pinEdit->setEnabled(false);

    pinConfirmEdit->setFixedWidth(widthForPin);
    pinConfirmEdit->setFixedWidth(widthForPin);

    QVBoxLayout *layout = findChild<QVBoxLayout *>("loginLayout");
    setLayout(layout);

    setWindowTitle("Connexion");
}

userLogin::~userLogin()
{
    delete ui;
}
