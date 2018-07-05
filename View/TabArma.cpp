#include "TabArma.h"

TabArma::TabArma(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): QWidget(parent), equipMap(equipMap), playerNumber(playerNumber), carP1(carP1), carP2(carP2){
	if(playerNumber == 1)
		arma = dynamic_cast<Arma*>((equipMap->find("ArmaP1"))->second);
	else
		arma = dynamic_cast<Arma*>((equipMap->find("ArmaP2"))->second);
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
	//connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	LblUsura = new QLabel("Usura:", this);
	usura = new QDoubleSpinBox(this);
	LblDannoBase = new QLabel("Danno Base:", this);
	DannoBase = new QDoubleSpinBox(this);
	LblForzaRichiesta = new QLabel("Forza Richiesta: ", this);
	forzaRichiesta = new QSpinBox(this);
	forzaRichiesta->setRange(5,99);
	LblIntelligenzaRichiesta = new QLabel("Intelligenza Richiesta:", this);
	intelligenzaRichiesta = new QSpinBox(this);
	intelligenzaRichiesta->setRange(5,99);
	operazioniArma = new OperazioniArma(this, arma, carP1);
	connectSignals();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(LblPeso, 0,0);
	winLayout->addWidget(peso, 0,1);
	winLayout->addWidget(LblUsura, 0,2);
	winLayout->addWidget(usura, 0,3);
	winLayout->addWidget(LblDannoBase, 1,0);
	winLayout->addWidget(DannoBase, 1,1);
	winLayout->addWidget(LblForzaRichiesta, 1,2);
	winLayout->addWidget(forzaRichiesta, 1, 3);
	winLayout->addWidget(LblIntelligenzaRichiesta, 2,0);
	winLayout->addWidget(intelligenzaRichiesta, 2,1);
	winLayout->addWidget(operazioniArma, 2,2,3,2);
	FinishInit();
}

TabArma::TabArma(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber): QWidget(parent), equipMap(equipMap), playerNumber(playerNumber){
	carP1=nullptr;
	carP2=nullptr;
	arma=nullptr;
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
	//connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	LblUsura = new QLabel("Usura:", this);
	usura = new QDoubleSpinBox(this);
	LblDannoBase = new QLabel("Danno Base:", this);
	DannoBase = new QDoubleSpinBox(this);
	LblForzaRichiesta = new QLabel("Forza Richiesta: ", this);
	forzaRichiesta = new QSpinBox(this);
	forzaRichiesta->setRange(5,99);
	LblIntelligenzaRichiesta = new QLabel("Intelligenza Richiesta:", this);
	intelligenzaRichiesta = new QSpinBox(this);
	intelligenzaRichiesta->setRange(5,99);
	operazioniArma = nullptr;
	connectSignals();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(LblPeso, 0,0);
	winLayout->addWidget(peso, 0,1);
	winLayout->addWidget(LblUsura, 0,2);
	winLayout->addWidget(usura, 0,3);
	winLayout->addWidget(LblDannoBase, 1,0);
	winLayout->addWidget(DannoBase, 1,1);
	winLayout->addWidget(LblForzaRichiesta, 1,2);
	winLayout->addWidget(forzaRichiesta, 1, 3);
	winLayout->addWidget(LblIntelligenzaRichiesta, 2,0);
	winLayout->addWidget(intelligenzaRichiesta, 2,1);
	setLayout(winLayout);
}

void TabArma::FinishInit(){
	setLayout(winLayout);
	connect(operazioniArma, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
	connect(operazioniArma, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
}

void TabArma::setPeso(double d){
	arma->SetPeso(d);
}

void TabArma::setUsura(double d){
	arma->SetUsura(d);
}

void TabArma::setDannoBase(double d){
	arma->SetDannoBase(d);
}

void TabArma::setForzaRichiesta(int i){
	arma->SetForzaRichiesta(i);
}

void TabArma::setIntelligenzaRichiesta(int i){
	arma->SetIntelligenzaRichiesta(i);
}

void TabArma::connectSignals(){
	connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	connect(usura, SIGNAL(valueChanged(double)), this, SLOT(setUsura(double)));
	connect(DannoBase, SIGNAL(valueChanged(double)), this, SLOT(setDannoBase(double)));
	connect(forzaRichiesta, SIGNAL(valueChanged(int)), this, SLOT(setForzaRichiesta(int)));
	connect(intelligenzaRichiesta, SIGNAL(valueChanged(int)), this, SLOT(setIntelligenzaRichiesta(int)));
}
