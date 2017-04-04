#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("备忘录");
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(590,480);
    //设置圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),8,8);
    setMask(bmp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)//无边框窗口移动
{
    if (ReleaseCapture())
        SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    event->ignore();
}

void MainWindow::saveFile() //保存文件函数
{
    QString fileName = Dialog::usrkeyinput+".txt";
    QFile file(fileName);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<ui->writeEdit->toPlainText();
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_action_save_triggered() //保存按钮函数
{
    saveFile();
    ui->writeEdit->document()->setModified(false);
}

void MainWindow::loadFile(QString fileName3) //读取文件函数
{
    QFile file(fileName3);
    file.open(QFile::ReadWrite | QIODevice::Text);
    QTextStream in(&file);
    ui->writeEdit->setPlainText(in.readAll());
}

bool MainWindow::maybesave() //判断是否保存函数
{
    if(ui->writeEdit->document()->isModified())
    {


        //提示窗口的设置
        MyMessageBox warnbox;
        warnbox.setFixedSize(360, 170);
        warnbox.setWindowTitle("警告！");
        warnbox.setIcon(QMessageBox::Warning);
        warnbox.setText("尚未保存，是否保存？");
        QPushButton *yesBtn=warnbox.addButton("是",QMessageBox::YesRole);
        warnbox.addButton(tr("否"), QMessageBox::NoRole);
        QPushButton *cancelBtn = warnbox.addButton("取消",QMessageBox::RejectRole);
        warnbox.exec();
        if(warnbox.clickedButton()==yesBtn)
            saveFile();
        else if (warnbox.clickedButton()==cancelBtn)
            return false;

    /*
        savewarn savewarnbox;
        //savewarnbox.exec();
        switch (savewarnbox.exec()) {
        case :return true;break;
        case 1:saveFile();break;
        case 0:return false;break;

        default:break;
        }


        if(savewarnbox.exec()==QDialog::Accepted)
        {
            saveFile();
            return true;
        }
        else if(savewarnbox.exec()==QDialog::Rejected)
        {
            return true;
        }
        else return false;
        */
    }
       return true;
}

void MainWindow::logout()//注销函数
{
    this->close();
    Dialog *dlk=new Dialog;
    dlk->show();

}

void MainWindow::on_action_logout_triggered()
{
    lgoutwarn logwarnbox;
    if(logwarnbox.exec()==QDialog::Accepted)
    {
        logout();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) //关闭主页面窗口的事件函数
{
    if(maybesave()){
        event->accept();
    }else{
        event->ignore();
    }
}
