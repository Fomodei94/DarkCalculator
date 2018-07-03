#include "MainWindow.h"
#include "../Model/Caratteristiche.h"
#include<iostream>
#include "../Model/ArmaFisica.h"
#include "../Model/Equipaggiamento.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Dark Calculator");
    setFixedSize(1600,800);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    winLayout = new QGridLayout(centralWidget);
    mappaEquipaggiamenti = new std::map<std::string, Equipaggiamento*>();
    //mappaEquipaggiamenti["ArmaP1"] = new Arma();
    mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmaFisicaP1", new ArmaFisica()));
    mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmaFisicaP2", new ArmaFisica()));
    Caratteristiche *Caratt_P1, *Caratt_P2;
    Caratt_P1 = new Caratteristiche();
    Caratt_P2 = new Caratteristiche();
    CaratteristicheP1 = new Caratteristiche_gui(centralWidget, 1, Caratt_P1);
    CaratteristicheP2 = new Caratteristiche_gui(centralWidget, 2, Caratt_P2);
    EquipaggiamentoP1 = new TabWidget(centralWidget, mappaEquipaggiamenti, 1);
    EquipaggiamentoP2 = new TabWidget(centralWidget, mappaEquipaggiamenti, 2);


    winLayout->addWidget(CaratteristicheP1,0,0);
    winLayout->addWidget(CaratteristicheP2,0,1);
    winLayout->addWidget(EquipaggiamentoP1,1,0);
    winLayout->addWidget(EquipaggiamentoP2,1,1);
    setLayout(winLayout);
}

MainWindow::~MainWindow()
{

}
