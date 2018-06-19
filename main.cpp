#include "View/MainWindow.h"
#include "Model/Caratteristiche.h"
#include <QApplication>
#include<QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Caratteristiche Caratt_P1, Caratt_P2;
    MainWindow *mainWin = new MainWindow();
    mainWin->show();

    return app.exec();
}
