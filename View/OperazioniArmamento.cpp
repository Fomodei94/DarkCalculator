#include "OperazioniArmamento.h"

OperazioniArmamento::OperazioniArmamento(QWidget* parent, Armamento* armamento, Caratteristiche* car): QWidget(parent), armamentoIstanza(armamento), car(car){
	label = new QLabel("<h4>Operazioni Armamento </h4>", this);
	Equilibrio = new QPushButton("Equilibrio", this);
	VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	ConfrontaDifesa = new QPushButton("Confronta Difesa", this);
	Somma = new QPushButton("Somma", this);
	connectSignalsOperazioni();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(Equilibrio, 1,0);
	winLayout->addWidget(VerificaUsabilita,1,1);
	winLayout->addWidget(ConfrontaDifesa, 2,0);
	winLayout->addWidget(Somma,2,1);
	setLayout(winLayout);
}

void OperazioniArmamento::CalcolaEquilibrio(){
	try {
		double equilibrio = armamentoIstanza->Equilibrio(*car);
		emit MostraRisultatoNumerico(equilibrio);
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
	
}

void OperazioniArmamento::CalcolaUsabilita(){
		bool usabilita = armamentoIstanza->VerificaUsabilita(*car);
		emit MostraRisultatoBooleano(usabilita);
}

void OperazioniArmamento::CalcolaConfrontaDifesa() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Confronta Difesa con Armamento.");
	msg->show();
}

void OperazioniArmamento::CalcolaSomma() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Somma Difesa con Armamento.");
	msg->show();
}

void OperazioniArmamento::connectSignalsOperazioni(){
	connect(Equilibrio, SIGNAL(clicked()), this, SLOT(CalcolaEquilibrio()));
	connect(VerificaUsabilita, SIGNAL(clicked()), this, SLOT(CalcolaUsabilita()));
	connect(ConfrontaDifesa, SIGNAL(clicked()), this, SLOT(CalcolaConfrontaDifesa()));
	connect(Somma, SIGNAL(clicked()), this, SLOT(CalcolaSomma()));
};


