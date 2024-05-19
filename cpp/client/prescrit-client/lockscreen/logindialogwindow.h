#ifndef LOGINDIALOGWINDOW_H
#define LOGINDIALOGWINDOW_H

#include "../rpcclient.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class LoginDialogWindow;
}

class LoginDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialogWindow(QWidget *parent = nullptr);
    ~LoginDialogWindow();

private slots:
    void on_uNameEdit_editingFinished();

private:
    Ui::LoginDialogWindow *ui;

    static const QString noUsernameMessage;

    bool uNameValid = false, pOk = false, pinOk = false, confPinOk = false;

    /**
     * @brief checkAllFieldsComplete
     *
     * @details Checks that all the labels of the loginDialogWindow are
     * filled out with something. We don't want to be submitting any
     * empty fields
     *
     * @return True on all fields complete, false on noncompleted fields
     */
    bool checkAllFieldsComplete();
    void toggleOkButton();

    void displayStatusLabel(const QString &statusmessage);
    void hideStatusLabel(const QString &statusToHide);
};

#endif // LOGINDIALOGWINDOW_H
