#include "TabArma.h"

TabArma::TabArma(QWidget* parent):QWidget(parent){//}, Arma* armaptr): QWidget(parent), arma(armaptr){
	LblPeso = new QLabel("Peso:",this);
	peso = new QDoubleSpinBox(this);
	LblUsura = new QLabel("Usura:", this);
	usura = new QDoubleSpinBox(this);
	LblDannoBase = new QLabel("Danno Base:", this);
	DannoBase = new QSpinBox(this);
	LblForzaRichiesta = new QLabel("Forza Richiesta: ", this);
	forzaRichiesta = new QSpinBox(this);
	LblIntelligenzaRichiesta = new QLabel("Intelligenza Richiesta:", this);
	intelligenzaRichiesta = new QSpinBox(this);
	winLayout = new QGridLayout(this);
	winLayout->addWidget(LblPeso, 0,0);
	winLayout->addWidget(peso, 0,1);
	setLayout(winLayout);
}
