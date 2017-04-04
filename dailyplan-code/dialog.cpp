#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("登陆界面");
    setFixedSize(450,340); //设置固定窗口大小
    setWindowFlags(Qt::FramelessWindowHint); //设置无边框窗口
    loadstate();
    //设置圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),8,8);
    setMask(bmp);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::usrkeyinput;
QString Dialog::pwdvalue3;
QString Dialog::remusrkey;


void Dialog::mousePressEvent(QMouseEvent *event)//无边框窗口移动
{
    if (ReleaseCapture())
        SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    event->ignore();
}

void Dialog::on_signinBtn_clicked()  //登陆按钮函数
{    
        usrkeyinput=ui->usrLine->text().trimmed();
        QString pwdvalue=ui->pwdLine->text();
        QString pwdvalue1=signup::getProperty(usrkeyinput);
        pwdvalue3=pwdvalue1;

        message wbox;

        if(usrkeyinput.isEmpty()||pwdvalue.isEmpty())
        {
            wbox.message::mes1("   请输入用户信息！");
            wbox.exec();
            wbox.show();
        }
        else if(pwdvalue==pwdvalue1)
        {
            if(RememberPwd==true)
            {
                savestate();
            }
            else if(RememberPwd==false)
            {
                QSettings iniset("config.ini",QSettings::IniFormat);
                iniset.setValue("LoginSetting","0");
            }
            MainWindow *mainW=new MainWindow();
            mainW->loadFile(Dialog::usrkeyinput+".txt");
            mainW->show();
            this->close();
        }
        else
        {
            wbox.message::mes1("  用户名或密码错误！");
            wbox.exec();
            wbox.show();
        }
        ui->usrLine->setFocus();
        ui->pwdLine->clear();
    }

void Dialog::on_signupBtn_clicked() //注册按钮函数
{
    //this->hide();
    signup zck;
    if(zck.exec())
    {
        zck.show();
    }
   // this->show();
}

void Dialog::savestate()
{
    remusrkey=usrkeyinput;
    QSettings iniset("config.ini",QSettings::IniFormat);
    iniset.setValue("LoginSetting","1");
    signup::setProperty("/remusrpwd1/usr",remusrkey);
    signup::setProperty("/remusrpwd1/pwd",pwdvalue3);
}

void Dialog::loadstate()
{

    QSettings iniset("config.ini",QSettings::IniFormat);
    int RemPwd=iniset.value("LoginSetting","1").toInt();
    if(RemPwd==1)
    {
        QString remusr=signup::getProperty("/remusrpwd1/usr");
        QString rempwd=signup::getProperty("/remusrpwd1/usr");
        ui->usrLine->setText(remusr);
        ui->pwdLine->setText(rempwd);
        ui->rem_pwd->setChecked(true);
    }
}

void Dialog::on_rem_pwd_stateChanged(int state)//记住密码判断
{
    if(state==Qt::Checked)
    {
        RememberPwd=true;
    }
    else
    {
        RememberPwd=false;
    }
}
