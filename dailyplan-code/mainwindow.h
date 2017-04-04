#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <windows.h>
#include <QFileDialog>
#include <QAction>
#include <signup.h>
#include <dialog.h>
#include <QTextStream>
#include <QPushButton>
#include <QCloseEvent>
#include <QWidget>
#include <QStackedLayout>
#include <QBitmap>
#include <QPainter>
#include <lgoutwarn.h>
#include <savewarn.h>

namespace Ui {
class MainWindow;
}

class Dialog;
class QStackedLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void saveFile();  //保存文件函数声明
    void loadFile(QString fileName); //读取文件函数声明
    bool maybesave(); //判断是否需要保存
    void logout();//注销函数声明
    void closeEvent(QCloseEvent *event); //窗口关闭的函数声明
    void mousePressEvent(QMouseEvent *event);//设置窗口可移动

private slots:
    void on_action_save_triggered(); //保存按钮的函数声明

    void on_action_logout_triggered();

private:
    Ui::MainWindow *ui;
    bool isUntitled;
    QString curfile;
};

class MyMessageBox : public QMessageBox
{
protected:
    void showEvent(QShowEvent* event) //窗口关闭函数的定义
    {
    QMessageBox::showEvent(event);
    setFixedSize(360, 170);
    }
};

#endif // MAINWINDOW_H
