#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

    void sign_up();

private slots:
    void on_signinBtn_clicked();

    void on_signupBtn_clicked();

private:
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
