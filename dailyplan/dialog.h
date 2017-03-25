#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<signup.h>
#include<QMessageBox>
#include <QString>
#include <QSettings>
#include <windows.h>
#include <mainwindow.h>
#include <QMouseEvent>
#include <message.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    static QString usrkeyinput;

//test
//void paintEvent(QPaintEvent* event);
//bool nativeEvent(const QByteArray&eventType, void *message, long *result);


private slots:
    void on_signinBtn_clicked();
    void on_signupBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
