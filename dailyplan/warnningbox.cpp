#include "warnningbox.h"
#include "ui_warnningbox.h"

warnningbox::warnningbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warnningbox)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(360,170);
}

warnningbox::~warnningbox()
{
    delete ui;
}



void warnningbox::on_okbtn_clicked()
{
    MainWindow w;
    w.saveFile();
}



bool warnningbox::on_celbtn_clicked()
{
    return true;
}
