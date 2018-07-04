#include "MainWindow.h"
#include "../Model/Caratteristiche.h"
#include<iostream>
#include "../Model/ArmaFisica.h"
#include "../Model/Arma.h"
#include "../Model/Armamento.h"
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
    mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmaP1", new Arma()));
    mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmaP2", new Arma()));
	mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmamentoP1", new Armamento()));
    mappaEquipaggiamenti->insert(std::pair<std::string, Equipaggiamento*>("ArmamentoP2", new Armamento()));
    Caratteristiche *Caratt_P1, *Caratt_P2;
    Caratt_P1 = new Caratteristiche();
    Caratt_P2 = new Caratteristiche();
    CaratteristicheP1 = new Caratteristiche_gui(centralWidget, 1, Caratt_P1);
    CaratteristicheP2 = new Caratteristiche_gui(centralWidget, 2, Caratt_P2);
    EquipaggiamentoP1 = new TabWidget(centralWidget, mappaEquipaggiamenti, 1, Caratt_P1, Caratt_P2);
    EquipaggiamentoP2 = new TabWidget(centralWidget, mappaEquipaggiamenti, 2, Caratt_P1, Caratt_P2);
    Risultato = new QLabel("<h1>In Attesa Prima Operazione</h1>", this);
    lblRisultato = new QLabel("<h1>Risultato:</h1>", this);
    connect(EquipaggiamentoP1, SIGNAL(MostraRisultatoNumerico3(double)), this, SLOT(MostraRisultatoNumericoFinale(double)));
    connect(EquipaggiamentoP1, SIGNAL(MostraRisultatoNumerico3(double)), this, SLOT(MostraRisultatoNumericoFinale(double)));
    connect(EquipaggiamentoP1, SIGNAL(MostraRisultatoBooleano3(bool)), this, SLOT(MostraRisultatoBooleanoFinale(bool)));
    winLayout->addWidget(CaratteristicheP1,0,0);
    winLayout->addWidget(CaratteristicheP2,0,1);
    winLayout->addWidget(EquipaggiamentoP1,1,0);
    winLayout->addWidget(EquipaggiamentoP2,1,1);
    winLayout->addWidget(lblRisultato, 2, 0, 1, 2);
    winLayout->addWidget(Risultato, 3,0,1,2);
    setLayout(winLayout);
}

void MainWindow::MostraRisultatoNumericoFinale(double x){
    Risultato->setText(QString("<h1>%1<h1>").arg(x));
}

void MainWindow::MostraRisultatoBooleanoFinale(bool x){
	if(x)
		Risultato->setText("<h1>Arma Utilizzabile</h1>");
	else
		Risultato->setText("<h1>Arma NON Utilizzabile</h1>");
}

MainWindow::~MainWindow()
{

}
