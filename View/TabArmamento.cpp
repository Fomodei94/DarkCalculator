#include "TabArmamento.h"

TabArmamento::TabArmamento(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carattP1, Caratteristiche* carattP2): QWidget(parent), equipMap(equipMap), playerNumber(playerNumber), carattP1(carattP1), carattP2(carattP2){
	armamento = dynamic_cast<Armamento*>((equipMap->find("ArmamentoP1"))->second);
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
	//connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	LblUsura = new QLabel("Usura:", this);
	usura = new QDoubleSpinBox(this);
	LblDifesa= new QLabel("Difesa:", this);
	Difesa = new QDoubleSpinBox(this);
	LblVigoreRichiesto = new QLabel("Vigore Richiesto: ", this);
	vigoreRichiesto = new QSpinBox(this);
	vigoreRichiesto->setRange(5,99);
	//operazioniArmamento = new OperazioniArmamento(this, armamento, carattP1);
	//connectSignals();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(LblPeso, 0,0);
	winLayout->addWidget(peso, 0,1);
	winLayout->addWidget(LblUsura, 0,2);
	winLayout->addWidget(usura, 0,3);
	winLayout->addWidget(LblDifesa, 1,0);
	winLayout->addWidget(Difesa, 1,1);
	winLayout->addWidget(LblVigoreRichiesto, 1,2);
	winLayout->addWidget(vigoreRichiesto, 1, 3);
	//winLayout->addWidget(operazioniArmamento, 2,2,2,2);
	FinishInit();
}

TabArmamento::TabArmamento(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber): QWidget(parent), equipMap(equipMap), playerNumber(playerNumber){
	carattP1=nullptr;
	carattP2=nullptr;
	armamento=nullptr;
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
	//connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	LblUsura = new QLabel("Usura:", this);
	usura = new QDoubleSpinBox(this);
	LblDifesa = new QLabel("Difesa:", this);
	Difesa = new QDoubleSpinBox(this);
	LblVigoreRichiesto = new QLabel("Vigore Richiesto: ", this);
	vigoreRichiesto = new QSpinBox(this);
	vigoreRichiesto->setRange(5,99);
	//operazioniArmamento = new OperazioniArmamento(this, arma, caratt);
	//connectSignals();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(LblPeso, 0,0);
	winLayout->addWidget(peso, 0,1);
	winLayout->addWidget(LblUsura, 0,2);
	winLayout->addWidget(usura, 0,3);
	winLayout->addWidget(LblDifesa, 1,0);
	winLayout->addWidget(Difesa, 1,1);
	winLayout->addWidget(LblVigoreRichiesto, 1,2);
	winLayout->addWidget(vigoreRichiesto, 1, 3);
	FinishInit();
}

void TabArmamento::FinishInit(){
	setLayout(winLayout);
	//connect(operazioniArmamento, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
	//connect(operazioniArmamento, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
}

