#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>
#include <QTextBrowser>
#include <QMouseEvent>
#include <windows.h>
#include <QBitmap>
#include <QPainter>

namespace Ui {
class message;
}

class message : public QDialog
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = 0);
    ~message();
    void mes1(QString mes);//返回信息函数声明
   // void mousePressEvent(QMouseEvent *event); //设置窗口可移动

private:
    Ui::message *ui;
};

#endif // MESSAGE_H
