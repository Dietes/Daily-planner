#ifndef SAVEWARN_H
#define SAVEWARN_H

#include <QDialog>
#include <mainwindow.h>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <windows.h>

namespace Ui {
class savewarn;
}

class savewarn : public QDialog
{
    Q_OBJECT

public:
    explicit savewarn(QWidget *parent = 0);
    ~savewarn();


private slots:
    int on_YESbtn_clicked();

    void on_NObtn_clicked();

    int on_CANCELbtn_clicked();

private:
    Ui::savewarn *ui;
};

#endif // SAVEWARN_H
