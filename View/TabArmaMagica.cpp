#include "TabArmaMagica.h"

TabArmaMagica::TabArmaMagica(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): TabArma(parent, equipMap, playerNumber), carP1(carP1), carP2(carP2){
	FinishInit();
};

void TabArmaMagica::FinishInit() {
	LblFuoco = new QLabel("Percentuale Danno Fuoco:", this);
	LblMagico = new QLabel("Percentuale Danno Magico:", this);
	LblElettrico = new QLabel("Percentuale Danno Elettrico", this);
	LblOscuro = new QLabel("Percentuale Danno Oscurita:", this);
	LblScalingIntelligenza = new QLabel("Scaling Intelligenza:", this);
	LblScalingFede = new QLabel("Scaling Fede:", this);
	Fuoco = new QDoubleSpinBox(this);
	Fuoco->setRange(0,100);
	Fuoco->setValue(25);
	Magico = new QDoubleSpinBox(this);
	Magico->setRange(0,100);
	Magico->setValue(25);
	Elettrico = new QDoubleSpinBox(this);
	Elettrico->setRange(0,100);
	Elettrico->setValue(25);
	Oscuro = new QDoubleSpinBox(this);
	Oscuro->setRange(0,100);
	Oscuro->setValue(25);
	ScalingFede = new QComboBox(this);
	ScalingFede->addItem("E");
	ScalingFede->addItem("D");
	ScalingFede->addItem("C");
	ScalingFede->addItem("B");
	ScalingFede->addItem("A");
	ScalingFede->addItem("S");
	ScalingIntelligenza = new QComboBox(this);
	ScalingIntelligenza->addItem("E");
	ScalingIntelligenza->addItem("D");
	ScalingIntelligenza->addItem("C");
	ScalingIntelligenza->addItem("B");
	ScalingIntelligenza->addItem("A");
	ScalingIntelligenza->addItem("S");
	if (playerNumber == 1){
		armaMagica = dynamic_cast<ArmaMagica*>((equipMap->find("ArmaMagicaP1"))->second);
	}else{
		armaMagica = dynamic_cast<ArmaMagica*>((equipMap->find("ArmaMagicaP2"))->second);
	}
	operazioniArmaMagica = new OperazioniArmaMagica(this, armaMagica, carP1);
	//CONNECT
  connect(operazioniArmaMagica, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
  connect(operazioniArmaMagica, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
  connectSignalsArmaMagica();
  //LAYOUT
	winLayout->addWidget(LblFuoco, 3,0);
	winLayout->addWidget(Fuoco, 3,1);
	winLayout->addWidget(LblMagico, 4,0);
	winLayout->addWidget(Magico, 4,1);
	winLayout->addWidget(LblElettrico, 5,0);
	winLayout->addWidget(Elettrico, 5,1);
	winLayout->addWidget(LblOscuro, 6,0);
	winLayout->addWidget(Oscuro, 6,1);
	winLayout->addWidget(LblScalingIntelligenza, 7,0);
	winLayout->addWidget(ScalingIntelligenza, 7,1);
	winLayout->addWidget(LblScalingFede, 8,0);
	winLayout->addWidget(ScalingFede, 8,1);
	winLayout->addWidget(operazioniArmaMagica, 2,2,5,2);
	setLayout(winLayout);
}
//OVERRIDE SLOTS
void TabArmaMagica::setPeso(double d){
	armaMagica->SetPeso(d);
}

void TabArmaMagica::setUsura(double d){
	armaMagica->SetUsura(d);
}

void TabArmaMagica::setDannoBase(double d){
	armaMagica->SetDannoBase(d);
}

void TabArmaMagica::setForzaRichiesta(int i){
	armaMagica->SetForzaRichiesta(i);
}

void TabArmaMagica::setIntelligenzaRichiesta(int i){
	armaMagica->SetIntelligenzaRichiesta(i);
}

void TabArmaMagica::setFuoco(double d){
	armaMagica->SetFuoco(d);
}

void TabArmaMagica::setMagico(double d){
	armaMagica->SetMagico(d);
}

void TabArmaMagica::setElettrico(double d){
	armaMagica->SetElettrico(d);
}

void TabArmaMagica::setOscuro(double d){
	armaMagica->SetOscuro(d);
}

void TabArmaMagica::setScalingIntelligenza(int i){
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
	armaMagica->SetScalingIntelligenza(c);
}

void TabArmaMagica::setScalingFede(int i){
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
	armaMagica->SetScalingFede(c);
}

void TabArmaMagica::connectSignalsArmaMagica(){
	connect(Fuoco, SIGNAL(valueChanged(double)), this, SLOT(setFuoco(double)));
	connect(Magico, SIGNAL(valueChanged(double)), this, SLOT(setMagico(double)));
	connect(Elettrico, SIGNAL(valueChanged(double)), this, SLOT(setElettrico(double)));
	connect(Oscuro, SIGNAL(valueChanged(double)), this, SLOT(setOscuro(double)));
	connect(ScalingIntelligenza, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingIntelligenza(int)));
	connect(ScalingFede, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingFede(int)));
}

