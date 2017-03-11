#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("登陆界面");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_signinBtn_clicked()
{    
        QString usrkey=ui->usrLine->text().trimmed();
        QString pwdvalue=ui->pwdLine->text();
        QString pwdvalue1=signup::getProperty(usrkey);

        if(usrkey.isEmpty()||pwdvalue.isEmpty())
        {
            QMessageBox::warning(this,"警告","请输入用户信息！",QMessageBox::Ok);
        }
        else if(pwdvalue==pwdvalue1)
        {
            accept();
        }
        else
        {
            QMessageBox::warning(this,"警告","用户名或密码错误！",QMessageBox::Ok);
        }
        ui->usrLine->setFocus();
        ui->pwdLine->clear();
    }

void Dialog::on_signupBtn_clicked()
{
    signup zck;
    if(zck.exec())
    {
        show();
    }
}
