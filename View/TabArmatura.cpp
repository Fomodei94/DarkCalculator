#include "TabArmatura.h"

TabArmatura::TabArmatura(QWidget* parent , std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2): TabArmamento(parent, equipMap, playerNumber), carP1(carP1), carP2(carP2){
	FinishInit();
};

void TabArmatura::FinishInit() {
	LblDifMagia = new QLabel("Difesa Magia:", this);
	LblDifOscurita = new QLabel("Difesa Oscurità:", this);
	LblDifFuoco = new QLabel("Difesa Fuoco:", this);
	LblDifElettricita = new QLabel("Difesa Elettricità:", this);
	LblDifTaglio = new QLabel("Difesa Taglio:", this);
	LblDifContundente = new QLabel("Difesa Contundente:", this);
	LblDifAffondo = new QLabel("Difesa Affondo:", this);
	DifMagia = new QDoubleSpinBox(this);
	DifOscurita = new QDoubleSpinBox(this);
	DifFuoco = new QDoubleSpinBox(this);
	DifElettricita = new QDoubleSpinBox(this);
	DifTaglio = new QDoubleSpinBox(this);
	DifContundente = new QDoubleSpinBox(this);
	DifAffondo = new QDoubleSpinBox(this);
	if (playerNumber == 1){
		armatura = dynamic_cast<Armatura*>((equipMap->find("ArmaturaP1"))->second);
	}else{
		armatura = dynamic_cast<Armatura*>((equipMap->find("ArmaturaP2"))->second);
	}

	operazioniArmatura = new OperazioniArmatura(this, armatura, carP1);

	//CONNECT
	connectSignalsArmatura();
	connect(operazioniArmatura, SIGNAL(MostraRisultatoNumerico(double)), this, SIGNAL(MostraRisultatoNumerico2(double)));
	connect(operazioniArmatura, SIGNAL(MostraRisultatoBooleano(bool)), this, SIGNAL(MostraRisultatoBooleano2(bool)));

	//LAYOUT
	winLayout->addWidget(LblDifMagia, 2,0);
	winLayout->addWidget(DifMagia, 2,1);
	winLayout->addWidget(LblDifOscurita, 3,0);
	winLayout->addWidget(DifOscurita, 3,1);
	winLayout->addWidget(LblDifFuoco, 4,0);
	winLayout->addWidget(DifFuoco, 4,1);
	winLayout->addWidget(LblDifElettricita, 5,0);
	winLayout->addWidget(DifElettricita, 5,1);
	winLayout->addWidget(LblDifTaglio, 2,2);
	winLayout->addWidget(DifTaglio, 2,3);
	winLayout->addWidget(LblDifContundente, 3,2);
	winLayout->addWidget(DifContundente, 3,3);
	winLayout->addWidget(LblDifAffondo, 4,2);
	winLayout->addWidget(DifAffondo, 4,3);
	winLayout->addWidget(operazioniArmatura, 5,2,5,3);
	setLayout(winLayout);
}

void TabArmatura::update(){
    //Cose qui
}
//OVERRIDE SLOTS
void TabArmatura::setPeso(double d){
	armatura->SetPeso(d);
}

void TabArmatura::setUsura(double d){
	armatura->SetUsura(d);
}

void TabArmatura::setDifesa(double d){
	armatura->SetDifesa(d);
}

void TabArmatura::setVigoreRichiesto(int i){
	armatura->SetVigoreRichiesto(i);
}

void TabArmatura::setDifMagia(double d) {
	armatura->SetDifesaMagica(d);
}

void TabArmatura::setDifOscurita(double d) {
	armatura->SetDifesaOscurita(d);
}

void TabArmatura::setDifFuoco(double d) {
	armatura->SetDifesaFuoco(d);
}

void TabArmatura::setDifElettricita(double d) {
	armatura->SetDifesaElettricita(d);
}

void TabArmatura::setDifTaglio(double d) {
	armatura->SetDifesaTaglio(d);
}

void TabArmatura::setDifContundente(double d) {
	armatura->SetDifesaContundente(d);
}

void TabArmatura::setDifAffondo(double d) {
	armatura->SetDifesaAffondo(d);
}

void TabArmatura::connectSignalsArmatura() {
	connect(DifMagia, SIGNAL(valueChanged(double)), this, SLOT(setDifMagia(double)));
	connect(DifOscurita, SIGNAL(valueChanged(double)), this, SLOT(setDifOscurita(double)));
	connect(DifFuoco, SIGNAL(valueChanged(double)), this, SLOT(setDifFuoco(double)));
	connect(DifElettricita, SIGNAL(valueChanged(double)), this, SLOT(setDifElettricita(double)));
	connect(DifTaglio, SIGNAL(valueChanged(double)), this, SLOT(setDifTaglio(double)));
	connect(DifContundente, SIGNAL(valueChanged(double)), this, SLOT(setDifContundente(double)));
	connect(DifAffondo, SIGNAL(valueChanged(double)), this, SLOT(setDifAffondo(double)));
}
