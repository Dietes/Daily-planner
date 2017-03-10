﻿#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<signup.h>
#include<QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_signinBtn_clicked();

    void on_signupBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
