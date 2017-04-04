#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<signup.h>
#include<QMessageBox>
#include <QString>
#include <QSettings>
#include <windows.h>
#include <mainwindow.h>
#include <QMouseEvent>
#include <message.h>
#include <QBitmap>
#include <QPainter>

namespace Ui {
class Dialog;
}



class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    static QString usrkeyinput; //输入的用户名变量
    static QString pwdvalue3; //输入的密码变量
    static QString remusrkey;
    void savestate();
    void loadstate();
    bool RememberPwd;
    void mousePressEvent(QMouseEvent *event);//设置窗口可移动

private slots:
    void on_signinBtn_clicked(); //sign in 按钮函数声明
    void on_signupBtn_clicked(); //sign up 按钮函数声明
    void on_rem_pwd_stateChanged(int state);//记住密码的函数声明



private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
