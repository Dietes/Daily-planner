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
 //   w.loadFile(QDir::currentPath()+signup::usrkey+".txt");
    w.loadFile(QDir::currentPath()+Dialog::usrkeyinput+".txt");
    w.show();
    return a.exec();
   }
   else return 0;
}
