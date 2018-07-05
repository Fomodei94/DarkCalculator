#include "OperazioniArmatura.h"

OperazioniArmatura::OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car): QWidget(parent), armaturaIstanza(armatura), car(car){
	label = new QLabel("<h4>Operazioni Armatura</h4>", this);
	VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	Equilibrio = new QPushButton("Equilibrio", this);
	Appesantisci = new QPushButton("Appesantisci", this);
	Alleggerisci = new QPushButton("Alleggerisci", this);
	CottaDiMaglia = new QPushButton("Cotta di Maglia", this);
	Sopravvivenza = new QPushButton("Sopravvivenza", this);
	ConfrontaDifesa = new QPushButton("Confronta Difesa", this);
	
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(VerificaUsabilita, 1,0);
	winLayout->addWidget(Equilibrio, 1,1);
	winLayout->addWidget(Appesantisci,2,0);
	winLayout->addWidget(Alleggerisci,2,1);
	winLayout->addWidget(CottaDiMaglia,3,0);
	winLayout->addWidget(Sopravvivenza,3,1);
	winLayout->addWidget(ConfrontaDifesa,4,0);
	setLayout(winLayout);
}

void OperazioniArmatura::CalcolaUsabilita() {
	bool usabilita = armaturaIstanza->VerificaUsabilita(*car);
	emit MostraRisultatoBooleano(usabilita);
}

void OperazioniArmatura::CalcolaEquilibrio() {
	double equilibrio = armaturaIstanza->Equilibrio(*car);
	emit MostraRisultatoNumerico(equilibrio);
}
