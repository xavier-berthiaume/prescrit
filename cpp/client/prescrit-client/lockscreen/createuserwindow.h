#ifndef CREATEUSERWINDOW_H
#define CREATEUSERWINDOW_H

#include <QDialog>

namespace Ui {
class createUserWindow;
}

class createUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit createUserWindow(QWidget *parent = nullptr);
    ~createUserWindow();

private:
    Ui::createUserWindow *ui;
};

#endif // CREATEUSERWINDOW_H
