#include "TabArmaMagica.h"

TabArmaMagica::TabArmaMagica(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): QWidget(parent), equipMap(equipMap), playerNumber(playerNumber), carP1(carP1), carP2(carP2){
	if (playerNumber == 1){
		armaMagica = dynamic_cast<ArmaMagica*>((equipMap->find("ArmaMagicaP1"))->second);
	}else{
		armaMagica = dynamic_cast<ArmaMagica*>((equipMap->find("ArmaMagicaP2"))->second);
	}
	operazioniArmaMagica = new OperazioniArmaMagica(this, armaMagica, carP1);
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
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
  connectSignalsArmaMagica();
  //LAYOUT
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
	winLayout->addWidget(operazioniArmaMagica, 2,2,5,2);
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
	FinishInit();
};

void TabArmaMagica::FinishInit() {
	setLayout(winLayout);
	//CONNECT
  connect(operazioniArmaMagica, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
  connect(operazioniArmaMagica, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
}

void TabArmaMagica::update(){
	Fuoco->setValue(armaMagica->GetFuoco());
	Magico->setValue(armaMagica->GetMagico());
	Elettrico->setValue(armaMagica->GetElettrico());
	Oscuro->setValue(armaMagica->GetOscuro());
	usura->setValue(armaMagica->GetUsura());
}


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
	connect(peso, SIGNAL(valueChanged(double)), this, SLOT(setPeso(double)));
	connect(usura, SIGNAL(valueChanged(double)), this, SLOT(setUsura(double)));
	connect(DannoBase, SIGNAL(valueChanged(double)), this, SLOT(setDannoBase(double)));
	connect(forzaRichiesta, SIGNAL(valueChanged(int)), this, SLOT(setForzaRichiesta(int)));
	connect(intelligenzaRichiesta, SIGNAL(valueChanged(int)), this, SLOT(setIntelligenzaRichiesta(int)));
	connect(Fuoco, SIGNAL(valueChanged(double)), this, SLOT(setFuoco(double)));
	connect(Magico, SIGNAL(valueChanged(double)), this, SLOT(setMagico(double)));
	connect(Elettrico, SIGNAL(valueChanged(double)), this, SLOT(setElettrico(double)));
	connect(Oscuro, SIGNAL(valueChanged(double)), this, SLOT(setOscuro(double)));
	connect(ScalingIntelligenza, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingIntelligenza(int)));
	connect(ScalingFede, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingFede(int)));
	connect(operazioniArmaMagica, SIGNAL(update()), this, SLOT(update()));
}

