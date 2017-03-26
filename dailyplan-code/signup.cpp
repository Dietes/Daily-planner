#include "signup.h"
#include "ui_signup.h"
#include <windows.h>

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle("注册界面");
    setFixedSize(450,390);
    setWindowFlags(Qt::FramelessWindowHint);
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
    QString fileN=fileName1+".txt";
    QFile file(fileN);
    file.open(QIODevice::WriteOnly | QIODevice::Text );
}

QString signup::usrkey;

void signup::on_signupokBtn_clicked()
{
    QString usrinput=ui->usrlineEdit->text();
    QString pwdinput=ui->pwdlineEdit->text()=ui->pwdlineEdit2->text();
    message wbox;

    if(usrinput.isEmpty()||pwdinput.isEmpty())
    {
        wbox.message::mes1("   请输入注册信息！");
        wbox.exec();
        wbox.show();
    }

    else if(usrkey==usrinput)
    {
        wbox.message::mes1("   用户名已经存在！");
        wbox.exec();
        wbox.show();
        ui->usrlineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->pwdlineEdit2->clear();
        ui->usrlineEdit->setFocus();
    }

    else if(ui->pwdlineEdit->text()!=ui->pwdlineEdit2->text())
    {
        wbox.message::mes1(" 两次密码输入不一致！");
        wbox.exec();
        wbox.show();
        ui->pwdlineEdit->clear();
        ui->pwdlineEdit2->clear();
        ui->pwdlineEdit->setFocus();
    }

    else
    {
        usrkey=ui->usrlineEdit->text();
        usrvalue=ui->pwdlineEdit->text();
        setProperty(usrkey,usrvalue);
        wbox.message::mes1("      注册成功！");
        wbox.exec();
        wbox.show();
        newFile(usrkey);
        close();
    }
}
