#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QSettings>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();
    void setProperty(QString key,QString value);
    static QString getProperty(QString key);
    void newFile(QString fileName1);
    static QString usrkey;
    QString usrvalue;

private slots:
    void on_signupokBtn_clicked();

private:
    Ui::signup *ui;
    QString FN;
};

#endif // SIGNUP_H
