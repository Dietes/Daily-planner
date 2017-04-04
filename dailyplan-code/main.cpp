#include "mainwindow.h"
#include <QApplication>
#include<dialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    Dialog loginbox;
   loginbox.exec();

    /*
    if(loginbox.exec()==QDialog::Accepted)
   {
    w.loadFile(Dialog::usrkeyinput+".txt");
    w.show();
    return a.exec();
   }
    else return 0;
*/
   return a.exec();
}
