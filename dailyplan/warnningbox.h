#ifndef WARNNINGBOX_H
#define WARNNINGBOX_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class warnningbox;
}

class warnningbox : public QDialog
{
    Q_OBJECT

public:
    explicit warnningbox(QWidget *parent = 0);
    ~warnningbox();
    void warnbox();

private slots:
    void on_okbtn_clicked();

    bool on_celbtn_clicked();

private:
    Ui::warnningbox *ui;
};

#endif // WARNNINGBOX_H
