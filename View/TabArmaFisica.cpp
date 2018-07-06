#include "TabArmaFisica.h"

TabArmaFisica::TabArmaFisica(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): TabArma(parent, equipMap, playerNumber), carP1(carP1), carP2(carP2){
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
	if (playerNumber == 1){
		armaFisica = dynamic_cast<ArmaFisica*>((equipMap->find("ArmaFisicaP1"))->second);
	}else{
		armaFisica = dynamic_cast<ArmaFisica*>((equipMap->find("ArmaFisicaP2"))->second);
	}
	operazioniArmaFisica = new OperazioniArmaFisica(this, armaFisica, carP1);
	//CONNECT
  connect(operazioniArmaFisica, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
  connect(operazioniArmaFisica, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));
  connectSignalsArmaFisica();
  //LAYOUT
	winLayout->addWidget(LblTipoDanno, 3,0);
	winLayout->addWidget(TipoDanno, 3,1);
	winLayout->addWidget(LblScalingForza, 4,0);
	winLayout->addWidget(ScalingForza, 4,1);
	winLayout->addWidget(LblScalingDestrezza, 5,0);
	winLayout->addWidget(ScalingDestrezza, 5,1);
	winLayout->addWidget(operazioniArmaFisica, 2,2,4,2);
	setLayout(winLayout);
}

void TabArmaFisica::update(){
    peso->setValue(armaFisica->GetPeso());
    int i;
    switch (armaFisica->GetScalingForza()){
        case 'E':
            i=0;
            break;
        case 'D':
            i=1;
            break;
        case 'C':
            i=2;
            break;
        case 'B':
            i=3;
            break;
        case 'A':
            i=4;
            break;
        case 'S':
            i=5;
            break;
    }
    ScalingForza->setCurrentIndex(i);
    switch (armaFisica->GetScalingDestrezza()){
        case 'E':
            i=0;
            break;
        case 'D':
            i=1;
            break;
        case 'C':
            i=2;
            break;
        case 'B':
            i=3;
            break;
        case 'A':
            i=4;
            break;
        case 'S':
            i=5;
            break;
    }
    ScalingDestrezza->setCurrentIndex(i);
}

//OVERRIDE SLOTS
void TabArmaFisica::setPeso(double d){
	armaFisica->SetPeso(d);
}

void TabArmaFisica::setUsura(double d){
	armaFisica->SetUsura(d);
}

void TabArmaFisica::setDannoBase(double d){
	armaFisica->SetDannoBase(d);
}

void TabArmaFisica::setForzaRichiesta(int i){
	armaFisica->SetForzaRichiesta(i);
}

void TabArmaFisica::setIntelligenzaRichiesta(int i){
	armaFisica->SetIntelligenzaRichiesta(i);
}

void TabArmaFisica::setTipoDanno(int i){
	char c;
	switch(i)
	{
		case 0 :
			c='T';
			break;
		case 1 :
			c='A';
			break;
		case 2 :
			c='C';
			break;
	}
	armaFisica->SetTipoDanno(c);
}

void TabArmaFisica::setScalingForza(int i){
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
	armaFisica->SetScalingForza(c);
}

void TabArmaFisica::setScalingDestrezza(int i){
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
	armaFisica->SetScalingDestrezza(c);
}

void TabArmaFisica::connectSignalsArmaFisica(){
	connect(TipoDanno, SIGNAL(currentIndexChanged(int)), this, SLOT(setTipoDanno(int)));
	connect(ScalingForza, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingForza(int)));
	connect(ScalingDestrezza, SIGNAL(currentIndexChanged(int)), this, SLOT(setScalingDestrezza(int)));
        connect(operazioniArmaFisica, SIGNAL(update()), this, SLOT(update()));
}
