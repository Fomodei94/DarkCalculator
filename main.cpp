#include "View/MainWindow.h"
#include <QApplication>
#include<QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mainWin = new MainWindow();
    mainWin->show();

    return app.exec();
}
