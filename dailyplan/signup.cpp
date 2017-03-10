#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle("注册界面");
}

signup::~signup()
{
    delete ui;
}

void signup::on_signupokBtn_clicked()
{
    QString usrinput=ui->usrlineEdit->text();
    QString pwdinput=ui->pwdlineEdit->text()=ui->pwdlineEdit2->text();

    if(usrinput.isEmpty()||pwdinput.isEmpty())
    {
        QMessageBox::warning(this, tr("警告"),tr("请输入注册信息！"),QMessageBox::Ok);
    }

    else if(ui->pwdlineEdit->text()!=ui->pwdlineEdit2->text())
    {
        QMessageBox::warning(this, tr("警告"),tr("两次密码输入不一致！"),QMessageBox::Ok);
        ui->pwdlineEdit->clear();
        ui->pwdlineEdit2->clear();
        ui->pwdlineEdit->setFocus();
    }

    else
    {
        QMessageBox::information(this, tr("恭喜"),tr("注册成功！"),QMessageBox::Ok);
        close();
    }
}
