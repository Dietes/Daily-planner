#include "signup.h"
#include "ui_signup.h"
#include<QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    setWindowTitle("注册界面");
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_signupokBtn_clicked()
{
    QString pwdinput=ui->pwdeditLine->text()=ui->pwdeditLine2->text();


    QString usrinput=ui->usreditLine->text();
    if(usrinput.isEmpty()||pwdinput.isEmpty())
    {
        QMessageBox::warning(this, tr("警告"),tr("请输入注册信息！"),QMessageBox::Ok);
    }

    else if(ui->pwdeditLine->text()!=ui->pwdeditLine2->text())
    {
        QMessageBox::warning(this, tr("警告"),tr("两次密码输入不一致！"),QMessageBox::Ok);
    }

    else
    {
        QMessageBox::information(this, tr("恭喜"),tr("注册成功！"),QMessageBox::Ok);
    }


}
