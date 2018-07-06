#include "TabScudo.h"

TabScudo::TabScudo(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): TabArmamento(parent, equipMap, playerNumber), carP1(carP1), carP2(carP2){
	FinishInit();
};

void TabScudo::FinishInit() {
	LblStabilita = new QLabel("Stabilità:", this);
	LblAssorbMagico = new QLabel("Assorbimento Magico:", this);
	LblAssorbFisico = new QLabel("Assorbimento Fisico:", this);
	LblScalingVigore = new QLabel("Scaling Vigore:", this);
	AssorbMagico = new QDoubleSpinBox(this);
	AssorbFisico = new QDoubleSpinBox(this);
	Stabilita = new QSpinBox(this);
	ScalingVigore = new QComboBox(this);
	ScalingVigore->addItem("E");
	ScalingVigore->addItem("D");
	ScalingVigore->addItem("C");
	ScalingVigore->addItem("B");
	ScalingVigore->addItem("A");
	ScalingVigore->addItem("S");

	if (playerNumber == 1){
		scudo = dynamic_cast<Scudo*>((equipMap->find("ScudoP1"))->second);
	}else{
		scudo = dynamic_cast<Scudo*>((equipMap->find("ScudoP2"))->second);
	}

	operazioniScudo = new OperazioniScudo(this, scudo, carP1);

	//CONNECT
    connect(operazioniScudo, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
	connect(operazioniScudo, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
	connectSignalsScudo();
	//LAYOUT
	winLayout->addWidget(LblStabilita, 2,0);
	winLayout->addWidget(Stabilita, 2,1);
	winLayout->addWidget(LblAssorbMagico, 3,0);
	winLayout->addWidget(AssorbMagico, 3,1);
	winLayout->addWidget(LblAssorbFisico, 4,0);
	winLayout->addWidget(AssorbFisico, 4,1);
	winLayout->addWidget(LblScalingVigore, 5,0);
	winLayout->addWidget(ScalingVigore, 5,1);
	winLayout->addWidget(operazioniScudo, 2,2,4,3);
	setLayout(winLayout);
}

//OVERRIDE SLOTS
void TabScudo::setPeso(double d){
	scudo->SetPeso(d);
}

void TabScudo::setUsura(double d){
	scudo->SetUsura(d);
}

void TabScudo::setDifesa(double d){
	scudo->SetDifesa(d);
}

void TabScudo::setVigoreRichiesto(int i){
	scudo->SetVigoreRichiesto(i);
}

//SLOTS SCUDO
void TabScudo::setAssorbMagico(double d) {
	scudo->SetAssorbimentoMagico(d);
}

void TabScudo::setAssorbFisico(double d) {
	scudo->SetAssorbimentoFisico(d);
}

void TabScudo::setStabilita(int i) {
	scudo->SetStabilita(i);
}

void  TabScudo::setScalingVigore(int i) {
	char c;
	switch(i)
	{
		case 0 :
			c='E';
			break;
		case 1 :
			c='D';
			break;
		case 2 :
			c='C';
			break;
		case 3 :
			c='B';
			break;
		case 4 :
			c='A';
			break;
		case 5 :
			c='S';
			break;
	}
	scudo->SetScalingVigore(c);
}

void TabScudo::connectSignalsScudo() {
	connect(AssorbMagico, SIGNAL(valueChanged(double)), this, SLOT(setAssorbMagico(double)));
	connect(AssorbFisico, SIGNAL(valueChanged(double)), this, SLOT(setAssorbFisico(double)));
	connect(Stabilita, SIGNAL(valueChanged(int)), this, SLOT(setStabilita(int)));
	connect(ScalingVigore, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingVigore(int)));
}
