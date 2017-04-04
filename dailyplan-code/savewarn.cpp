#include "savewarn.h"
#include "ui_savewarn.h"

savewarn::savewarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savewarn)
{
    ui->setupUi(this);
    ui->setupUi(this);
    setFixedSize(360,170);
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

savewarn::~savewarn()
{
    delete ui;
}

/*
void savewarn::on_YESbtn_clicked()
{
    accepted();
}

void savewarn::on_NObtn_clicked()
{
    rejected();
}

void savewarn::on_CANCELbtn_clicked()
{
    close();
}
*/

int savewarn::on_YESbtn_clicked()
{
  //  accepted();
    return 1;
}

void savewarn::on_NObtn_clicked()
{
   // close();
   // return 2;
}

int savewarn::on_CANCELbtn_clicked()
{
   // rejected();
    return 0;
}
