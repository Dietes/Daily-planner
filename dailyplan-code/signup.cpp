#include "signup.h"
#include "ui_signup.h"
#include <windows.h>

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle("注册界面");
    setFixedSize(450,390); //设置固定窗口大小
    setWindowFlags(Qt::FramelessWindowHint);  //设置无边框窗口
    //设置圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),8,8);
    setMask(bmp);
}

signup::~signup()
{
    delete ui;
}

void signup::mousePressEvent(QMouseEvent *event)//无边框窗口移动
{
    if (ReleaseCapture())
        SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    event->ignore();
}

void signup::setProperty(QString key,QString value) //存储账号密码的函数
{
    QString fileName="config.ini";
    QSettings *settings=new QSettings(fileName,QSettings::IniFormat);
    settings->setValue(key,value);
}

QString signup::getProperty(QString key) //读取账号密码的函数
{
    QString fileName="config.ini";
    QSettings *settings=new QSettings(fileName,QSettings::IniFormat);
    return settings->value(key).toString();
}

void signup::newFile(QString fileName1) //建立新文档的函数
{
    QString fileN=fileName1+".txt";
    QFile file(fileN);
    file.open(QIODevice::WriteOnly | QIODevice::Text );
}

QString signup::usrkey;

void signup::on_signupokBtn_clicked() //注册按钮的函数
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
        this->close();
    }
}
