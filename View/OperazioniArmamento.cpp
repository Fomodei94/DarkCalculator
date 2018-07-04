#include "OperazioniArmamento.h"

OperazioniArmamento::OperazioniArmamento(QWidget* parent, Armamento* armamento, Caratteristiche* car): QWidget(parent), armamentoIstanza(armamento), car(car){
	label = new QLabel("<h4>Operazioni Armamento </h4>", this);
	Equilibrio = new QPushButton("Equilibrio", this);
	VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	connectSignalsOperazioni();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(Equilibrio, 1,0);
	winLayout->addWidget(VerificaUsabilita,1,1);
	setLayout(winLayout);
}

void OperazioniArmamento::CalcolaEquilibrio(){
	double equilibrio = armamentoIstanza->Equilibrio(*car);
	emit MostraRisultatoNumerico(equilibrio);
}

void OperazioniArmamento::CalcolaUsabilita(){
	bool usabilita = armamentoIstanza->VerificaUsabilita(*car);
	emit MostraRisultatoBooleano(usabilita);
}

void OperazioniArmamento::connectSignalsOperazioni(){
	connect(Equilibrio, SIGNAL(clicked()), this, SLOT(CalcolaEquilibrio()));
	connect(VerificaUsabilita, SIGNAL(clicked()), this, SLOT(CalcolaUsabilita()));
};


