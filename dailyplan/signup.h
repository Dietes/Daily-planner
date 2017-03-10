#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();

private slots:
    void on_signupokBtn_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
