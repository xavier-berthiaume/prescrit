#ifndef LOGINDIALOGWINDOW_H
#define LOGINDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class LoginDialogWindow;
}

class LoginDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialogWindow(QWidget *parent = nullptr);
    ~LoginDialogWindow();

private:
    Ui::LoginDialogWindow *ui;
};

#endif // LOGINDIALOGWINDOW_H
