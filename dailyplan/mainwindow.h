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

    void saveFile(QString fileName2);
    static void toload(QString fileName);
    void loadFile(QString fileName);

private slots:
    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;
    //
    bool isUntitled;
    QString curfile;
};

#endif // MAINWINDOW_H
