#include "TabArma.h"

TabArma::TabArma(QWidget* parent, Arma* armaptr): QWidget(parent), arma(armaptr){
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
