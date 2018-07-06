#include "OperazioniArmaP2.h"

OperazioniArmaP2::OperazioniArmaP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* car): QWidget(parent), equipMap(equipMap), car(car){
	label = new QLabel("<h4>Operazioni Arma P2</h4>", this);
	ConfrontaConArma = new QPushButton("Confronta con Arma", this);
	ConfrontaConArmaFisica = new QPushButton("Confronta con Arma Fisica", this);
	ConfrontaConArmaMagica = new QPushButton("Confronta con Arma Magica", this);
	SommaConArma = new QPushButton("Somma Con Arma", this);
	SommaConArmaFisica = new QPushButton("Somma con Arma Fisica", this);
	SommaConArmaMagica = new QPushButton("Somma con Arma Magica", this);
	Frantuma = new QPushButton("Frantuma", this);
	Sopravvivenza = new QPushButton("Sopravvivenza", this);
	HyperArmor = new QPushButton("Hyper Armor", this);
	SpezzaGuardia = new QPushButton("Spezza Guardia", this);
	connectSignalsOperazioni();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(ConfrontaConArma, 1,0);
	winLayout->addWidget(ConfrontaConArmaFisica, 1,1);
	winLayout->addWidget(ConfrontaConArmaMagica,2,0);
	winLayout->addWidget(SommaConArma,2,1);
	winLayout->addWidget(SommaConArmaFisica,3,0);
	winLayout->addWidget(SommaConArmaMagica,3,1);
	winLayout->addWidget(Frantuma,4,0);
	winLayout->addWidget(Sopravvivenza,4,1);
	winLayout->addWidget(HyperArmor,5,0);
	winLayout->addWidget(SpezzaGuardia,5,1);
	setLayout(winLayout);
}

