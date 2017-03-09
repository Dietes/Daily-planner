#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPushButton>
#include<QFileDialog>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("日程管理");
}

MainWindow::~MainWindow()
{
    delete ui;
}
