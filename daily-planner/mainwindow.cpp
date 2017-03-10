#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPushButton>
#include<QFileDialog>
#include<QTextStream>
#include<QAction>
#include<QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("备忘录");
}


MainWindow::~MainWindow()
{
    delete ui;
}
