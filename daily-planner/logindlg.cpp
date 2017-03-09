#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    setWindowTitle("登陆界面");
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_signinBtn_clicked()
{
    if(ui->usrLine->text().trimmed()==tr("admin")
            &&ui->pwdLine->text()==tr("admin"))
    {
       accept();
    }
    else{QMessageBox::warning(this, tr("Warning"),
                              tr("user name or password error!"),QMessageBox::Ok);}

    ui->pwdLine->clear();
}
