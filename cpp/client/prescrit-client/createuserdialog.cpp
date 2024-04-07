#include "createuserdialog.h"
#include "ui_createuserdialog.h"

#include <prescrit/globals.h>

createUserDialog::createUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUserDialog)
{
    ui->setupUi(this);

    QLineEdit *prenomLineEdit = findChild<QLineEdit *>("prenomEdit");
    QLineEdit *nomLineEdit = findChild<QLineEdit *>("nomEdit");
    QLineEdit *mdpLineEdit = findChild<QLineEdit *>("mdpEdit");

    QFont font = prenomLineEdit->font();
    QFontMetrics fontMetrics(font);

    int charWidth = fontMetrics.horizontalAdvance(QLatin1Char('X'));
    int widthForNameMaxChars = charWidth * MAXNAMELENGTH;
    int widthForPassMaxChars = charWidth * MAXPASSWORDLENGTH;

    prenomLineEdit->setFixedWidth(widthForNameMaxChars);
    nomLineEdit->setFixedWidth(widthForNameMaxChars);
    mdpLineEdit->setFixedWidth(widthForPassMaxChars);

    mdpLineEdit->setEchoMode(QLineEdit::Password);

    QVBoxLayout *layout = findChild<QVBoxLayout *>("dialogLayout");
    setLayout(layout);

    setWindowTitle("Créer un Utilisateur");

}

createUserDialog::~createUserDialog()
{
    delete ui;
}
