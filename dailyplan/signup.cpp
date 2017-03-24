#include "signup.h"
#include "ui_signup.h"
#include <windows.h>

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

void signup::setProperty(QString key,QString value)
{
    QString fileName="config.ini";
    QSettings *settings=new QSettings(fileName,QSettings::IniFormat);
    settings->setValue(key,value);
}

QString signup::getProperty(QString key)
{
    QString fileName="config.ini";
    QSettings *settings=new QSettings(fileName,QSettings::IniFormat);
    return settings->value(key," ").toString();
}

void signup::newFile(QString fileName1)
{
    QString fileN=QDir::currentPath()+fileName1+".txt";
    QFile file(fileN);
    file.open(QIODevice::WriteOnly | QIODevice::Text );
}

QString signup::usrkey;

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
        usrkey=ui->usrlineEdit->text();
        usrvalue=ui->pwdlineEdit->text();
        setProperty(usrkey,usrvalue);
        QMessageBox::information(this, tr("恭喜"),tr("注册成功！"),QMessageBox::Ok);
        newFile(usrkey);
        close();
    }
}
