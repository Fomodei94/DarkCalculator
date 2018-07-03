#include "MainWindow.h"
#include "../Model/Caratteristiche.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Dark Calculator");
    setFixedSize(1600,800);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    winLayout = new QGridLayout(centralWidget);
    Caratteristiche *Caratt_P1, *Caratt_P2;
    Caratt_P1 = new Caratteristiche();
    Caratt_P2 = new Caratteristiche();
    CaratteristicheP1 = new Caratteristiche_gui(centralWidget, 1, Caratt_P1);
    //CaratteristicheP2 = new Caratteristiche_gui(centralWidget, 2, Caratt_P2);
    EquipaggiamentoP1 = new TabWidget(centralWidget);
    //EquipaggiamentoP2 = new TabWidget(centralWidget);

    //winLayout->addWidget(CaratteristicheP1,0,0);
    //winLayout->addWidget(CaratteristicheP2,0,1);
    winLayout->addWidget(EquipaggiamentoP1,0,0);
    //winLayout->addWidget(EquipaggiamentoP2,1,1);
    setLayout(winLayout);
}

MainWindow::~MainWindow()
{

}
