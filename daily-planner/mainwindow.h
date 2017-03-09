#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void newFile();
    bool maybesave();
    bool save();

private:
    Ui::MainWindow *ui;
    bool isUnsave;//为真表示未保存，为假表示保存
};

#endif // MAINWINDOW_H
