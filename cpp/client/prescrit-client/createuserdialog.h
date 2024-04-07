#ifndef CREATEUSERDIALOG_H
#define CREATEUSERDIALOG_H

#include <QDialog>

namespace Ui {
class createUserDialog;
}

class createUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createUserDialog(QWidget *parent = nullptr);
    ~createUserDialog();

private:
    Ui::createUserDialog *ui;
};

#endif // CREATEUSERDIALOG_H
