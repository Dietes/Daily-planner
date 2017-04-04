#ifndef LGOUTWARN_H
#define LGOUTWARN_H

#include <QDialog>
#include <QMouseEvent>
#include <windows.h>
#include <QBitmap>
#include <QPainter>
#include <mainwindow.h>

namespace Ui {
class lgoutwarn;
}

class lgoutwarn : public QDialog
{
    Q_OBJECT

public:
    explicit lgoutwarn(QWidget *parent = 0);
    ~lgoutwarn();

private slots:
    void on_YESbtn_clicked();

private:
    Ui::lgoutwarn *ui;
};

#endif // LGOUTWARN_H
