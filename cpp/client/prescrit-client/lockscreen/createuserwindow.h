#ifndef CREATEUSERWINDOW_H
#define CREATEUSERWINDOW_H

#include "../rpcclient.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class createUserWindow;
}

class createUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit createUserWindow(QWidget *parent = nullptr);
    ~createUserWindow();

private slots:
    void on_fNameEdit_textChanged(const QString &arg1);
    void on_lNameEdit_textChanged(const QString &arg1);
    void on_uNameEdit_textChanged(const QString &arg1);
    void on_pEdit_textChanged(const QString &arg1);

private:
    Ui::createUserWindow *ui;

    bool fNameOk = false, lNameOk = false, uNameOk = false, pOk = false;

    bool checkAllFieldsComplete();
    void toggleOkButton();

    bool validateName(const QString &arg1);

    void displayStatusLabel(const QString &statusmessage);
    void hideStatusLabel(const QString &statusToHide);
};

#endif // CREATEUSERWINDOW_H
