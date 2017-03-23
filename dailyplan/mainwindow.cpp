﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::saveFile(QString fileName2)
{
    QFile file(fileName2);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out<<ui->writeEdit->toPlainText();
}

void MainWindow::on_action_save_triggered()
{
    QString nameFile=signup::usrkey;
    QString fileName = QDir::currentPath()+nameFile+".txt";
    if (!fileName.isEmpty())
        saveFile(fileName);
}
