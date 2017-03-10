#include "mainwindow.h"
#include <QApplication>
#include<dialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog loginbox;
   if(loginbox.exec()==QDialog::Accepted)
   {
    w.show();
    return a.exec();
   }
   else return 0;
}
