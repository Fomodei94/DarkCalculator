#include "OperazioniArmatura.h"

OperazioniArmatura::OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car): OperazioniArmamento(parent), armaturaIstanza(armatura), car(car){
	//label->setText("<h4>Operazioni Armatura<h4>");
	//VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	//Equilibrio = new QPushButton("Equilibrio", this);
	Appesantisci = new QPushButton("Appesantisci", this);
	Alleggerisci = new QPushButton("Alleggerisci", this);
	CottaDiMaglia = new QPushButton("Cotta di Maglia", this);
	Sopravvivenza = new QPushButton("Sopravvivenza", this);
	//ConfrontaDifesa = new QPushButton("Confronta Difesa", this);
	
	//winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(Appesantisci,3,0);
	winLayout->addWidget(Alleggerisci,3,1);
	winLayout->addWidget(CottaDiMaglia,4,0);
	winLayout->addWidget(Sopravvivenza,4,1);
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
