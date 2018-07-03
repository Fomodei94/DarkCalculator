#include "TabArmaFisica.h"

TabArmaFisica::TabArmaFisica(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* car): TabArma(parent, equipMap), playerNumber(playerNumber), car(car){
	FinishInit();
};

void TabArmaFisica::FinishInit() {
	LblTipoDanno = new QLabel("Tipo Danno:", this);
	LblScalingForza = new QLabel("Scaling Forza:", this);
	LblScalingDestrezza = new QLabel("Scaling Destrezza", this);
	TipoDanno = new QComboBox(this);
	TipoDanno->addItem("Taglio");
	TipoDanno->addItem("Affondo");
	TipoDanno->addItem("Contundente");
	ScalingForza = new QComboBox(this);
	ScalingForza->addItem("E");
	ScalingForza->addItem("D");
	ScalingForza->addItem("C");
	ScalingForza->addItem("B");
	ScalingForza->addItem("A");
	ScalingForza->addItem("S");
	ScalingDestrezza = new QComboBox(this);
	ScalingDestrezza->addItem("E");
	ScalingDestrezza->addItem("D");
	ScalingDestrezza->addItem("C");
	ScalingDestrezza->addItem("B");
	ScalingDestrezza->addItem("A");
	ScalingDestrezza->addItem("S");
	ArmaFisica* arma;
	if (playerNumber == 1){
		arma = dynamic_cast<ArmaFisica*>((equipMap->find("ArmaFisicaP1"))->second);
	}else{
		arma = dynamic_cast<ArmaFisica*>((equipMap->find("ArmaFisicaP2"))->second);
	}
	operazioni = new OperazioniArmaFisica(this, arma, car);
        connect(operazioni, SIGNAL(MostraDannoEffettivo(int)), this, SIGNAL(MostraDannoEffettivo2(int)));
	winLayout->addWidget(LblTipoDanno, 3,0);
	winLayout->addWidget(TipoDanno, 3,1);
	winLayout->addWidget(LblScalingForza, 4,0);
	winLayout->addWidget(ScalingForza, 4,1);
	winLayout->addWidget(LblScalingDestrezza, 5,0);
	winLayout->addWidget(ScalingDestrezza, 5,1);
	winLayout->addWidget(operazioni, 2,2,4,2);
	setLayout(winLayout);
}
