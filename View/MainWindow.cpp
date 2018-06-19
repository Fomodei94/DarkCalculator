#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Dark Calculator");
    setFixedSize(1400,600);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    CaratteristicheP1 = new Caratteristiche_gui(centralWidget);
}

MainWindow::~MainWindow()
{

}
