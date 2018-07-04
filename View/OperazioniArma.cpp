#include "OperazioniArma.h"

OperazioniArma::OperazioniArma(QWidget* parent, Arma* arma, Caratteristiche* car): QWidget(parent), armaIstanza(arma), car(car){
	label = new QLabel("<h4>Operazioni Arma </h4>", this);
	DannoEffettivo = new QPushButton("Danno Effettivo", this);
  //connect(DannoEffettivo, SIGNAL(clicked()), this, SLOT(CalcolaDannoEffettivo()));
	Efficacia = new QPushButton("Efficacia", this);
	VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	connectSignalsOperazioni();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(DannoEffettivo, 1,0);
	winLayout->addWidget(Efficacia, 1,1);
	winLayout->addWidget(VerificaUsabilita,2,0);
	setLayout(winLayout);
}

/*
void OperazioniArma::CalcolaDannoEffettivo(){
	double effettivo = armaIstanza->DannoEffettivo(*car);
  emit MostraDannoEffettivo(effettivo);
}
*/

void OperazioniArma::connectSignalsOperazioni(){};

