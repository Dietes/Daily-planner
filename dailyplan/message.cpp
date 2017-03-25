#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    setFixedSize(260,140);
    setWindowFlags(Qt::FramelessWindowHint);
}

message::~message()
{
    delete ui;
}

void message::mes1(QString mes)
{
    ui->textBrowser->setPlainText(mes);
}
