#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("备忘录");
 //   setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::saveFile(QString fileName2)
{
    QFile file(fileName2);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out<<ui->writeEdit->toPlainText();
}*/

void MainWindow::saveFile()
{
 //   QString fileName = QDir::currentPath()+Dialog::usrkeyinput+".txt";
    QString fileName = Dialog::usrkeyinput+".txt";
 //   MainWindow::output(fileName);
    QFile file(fileName);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<ui->writeEdit->toPlainText();
    QApplication::restoreOverrideCursor();
}
/*
void MainWindow::output(QString fileName)
{
    QFile file(fileName);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<ui->writeEdit->toPlainText();
    QApplication::restoreOverrideCursor();
}
*/
void MainWindow::on_action_save_triggered()
{
//    QString nameFile=signup::usrkey;
//    QString nameFile=Dialog::usrkeyinput;
//    QString fileName = QDir::currentPath()+nameFile+".txt";
//    if (!fileName.isEmpty())
    saveFile();
    ui->writeEdit->document()->setModified(false);
}

void MainWindow::loadFile(QString fileName3)
{
    QFile file(fileName3);
    file.open(QFile::ReadWrite | QIODevice::Text);
    QTextStream in(&file);
    ui->writeEdit->setPlainText(in.readAll());
}

bool MainWindow::maybesave()
{
    if(ui->writeEdit->document()->isModified())
    {        
        MyMessageBox warnbox;
        warnbox.setFixedSize(360, 170);
     //   warnbox.setStyleSheet("border-image: url(:/myjpg/warnbox.jpg)");

        warnbox.setWindowTitle("警告！");
        warnbox.setIcon(QMessageBox::Warning);
        warnbox.setText("尚未保存，是否保存？");
        QPushButton *yesBtn=warnbox.addButton("是",QMessageBox::YesRole);
     //  yesBtn->setStyleSheet("border-image: url(:/myjpg/YES.jpg)");
        warnbox.addButton(tr("否"), QMessageBox::NoRole);
        QPushButton *cancelBtn = warnbox.addButton("取消",QMessageBox::RejectRole);
        warnbox.exec();
        if(warnbox.clickedButton()==yesBtn)
            saveFile();
        else if (warnbox.clickedButton()==cancelBtn)
            return false;

    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybesave()){
        event->accept();
    }else{
        event->ignore();
    }
}
