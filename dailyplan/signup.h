#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QSettings>
#include <QtSql/QSqlTableModel>
#include <QDebug>

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

private slots:
    void on_signupokBtn_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
