#include "MainWindow.h"
#include "../Model/Caratteristiche.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Dark Calculator");
    setFixedSize(1400,600);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    Caratteristiche *Caratt_P1, *Caratt_P2;
    Caratt_P1 = new Caratteristiche;
    Caratt_P2 = new Caratteristiche;
    CaratteristicheP1 = new Caratteristiche_gui(centralWidget, 1, Caratt_P1);
    //CaratteristicheP2 = new Caratteristiche_gui(centralWidget, 2, Caratt_P2);
}

MainWindow::~MainWindow()
{

}
