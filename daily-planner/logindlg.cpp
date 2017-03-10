#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>
#include <signup.h>
#include <QtWidgets>


LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);


    setWindowTitle("登陆界面");
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_signinBtn_clicked()
{
    if(ui->usrLine->text().trimmed()==tr("admin")
            &&ui->pwdLine->text()==tr("admin"))
    {
       accept();
    }
    else{QMessageBox::warning(this, tr("警告"),
                              tr("用户名或密码错误！"),QMessageBox::Ok);}

    ui->pwdLine->clear();
}


void LoginDlg::on_signupBtn_clicked()
{
    SignUp zck;
    if(zck.exec()){
        show();
    }
}
