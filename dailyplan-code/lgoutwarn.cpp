#include "lgoutwarn.h"
#include "ui_lgoutwarn.h"

lgoutwarn::lgoutwarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lgoutwarn)
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

lgoutwarn::~lgoutwarn()
{
    delete ui;
}


void lgoutwarn::on_YESbtn_clicked()
{
    accept();
}
