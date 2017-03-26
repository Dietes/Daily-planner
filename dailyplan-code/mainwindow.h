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
#include <QPushButton>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void saveFile();
    void loadFile(QString fileName);
    bool maybesave();
    void closeEvent(QCloseEvent *event);
    //void output(QString fileName);

private slots:
    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;
    bool isUntitled;
    QString curfile;

};

class MyMessageBox : public QMessageBox
{
protected:
    void showEvent(QShowEvent* event) {
    QMessageBox::showEvent(event);
    setFixedSize(360, 170);
    }
};

#endif // MAINWINDOW_H
