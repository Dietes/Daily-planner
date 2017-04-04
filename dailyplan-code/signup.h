#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QMouseEvent>
#include <message.h>
#include <dialog.h>
#include <QBitmap>
#include <QPainter>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();
    static void setProperty(QString key,QString value); //存储账号密码函数声明
    static QString getProperty(QString key); //读取账号密码函数声明
    void newFile(QString fileName1); //新建文件的函数声明
    static QString usrkey; //用户名的变量
    QString usrvalue; //密码变量
    void mousePressEvent(QMouseEvent *event);//设置窗口可移动

private slots:
    void on_signupokBtn_clicked(); //注册按钮的函数声明

private:
    Ui::signup *ui;
    QString FN;
};

#endif // SIGNUP_H
