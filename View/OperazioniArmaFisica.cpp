#include "OperazioniArmaFisica.h"

OperazioniArmaFisica::OperazioniArmaFisica(QWidget* parent, ArmaFisica* arma, Caratteristiche* car): OperazioniArma(parent), armaFisicaIstanza(arma), car(car){
	Raffina = new QPushButton("Raffina", this);
	Frantuma = new QPushButton("Frantuma", this);
	Cristallizza = new QPushButton("Cristallizza", this);
	Riforgia = new QPushButton("Riforgia", this);
	connectSignalsOperazioniProprie();
	winLayout->addWidget(Raffina,3,1);
	winLayout->addWidget(Frantuma,4,0);
	winLayout->addWidget(Cristallizza,4,1);
	winLayout->addWidget(Riforgia,5,0);
	setLayout(winLayout);
}

void OperazioniArmaFisica::CalcolaDannoEffettivo(){
	double effettivo = armaFisicaIstanza->DannoEffettivo(*car);
  emit MostraRisultatoNumerico(effettivo);
}

void OperazioniArmaFisica::connectSignalsOperazioniProprie(){}
