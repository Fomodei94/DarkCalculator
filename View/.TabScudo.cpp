#include "TabScudo.h"

TabScudo::TabScudo(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): TabScudo(parent, equipMap, playerNumber), carP1(carP1), carP2(carP2){
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
   connect(operazioniScudo, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
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

