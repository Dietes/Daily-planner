#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <windows.h>
#include <QFileDialog>
#include <QAction>
#include <signup.h>
#include <dialog.h>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //测试
//    void newFile();
//    bool maybeSave();
    void saveFile(QString fileName2);

private slots:
    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;
    //
    bool isUntitled;
    QString curfile;
};

#endif // MAINWINDOW_H
