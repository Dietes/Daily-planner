#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    setFixedSize(260,140);
    setWindowFlags(Qt::FramelessWindowHint); //设置无边框窗口
    //设置圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),6,6);
    setMask(bmp);
}

message::~message()
{
    delete ui;
}
/*
void message::mousePressEvent(QMouseEvent *event)//无边框窗口移动
{
    if (ReleaseCapture())
        SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    event->ignore();
}
*/

void message::mes1(QString mes)  //返回信息的函数
{
    ui->textBrowser->setPlainText(mes);
}
