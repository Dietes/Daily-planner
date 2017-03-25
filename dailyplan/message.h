#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>
#include <QTextBrowser>

namespace Ui {
class message;
}

class message : public QDialog
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = 0);
    ~message();
    void mes1(QString mes);

private:
    Ui::message *ui;
};

#endif // MESSAGE_H
