#include "OperazioniScudo.h"

OperazioniScudo::OperazioniScudo(QWidget* parent, Scudo* scudo, Caratteristiche* car): OperazioniArmamento(parent), scudoIstanza(scudo), car(car){
	label->setText("<h4>Operazioni Scudo </h4>");
	Spezzaguardia = new QPushButton("Spezzaguardia", this);
	Parata = new QPushButton("Parata", this);
	connectSignalsOperazioniScudo();
	winLayout->addWidget(Spezzaguardia,3,0);
	winLayout->addWidget(Parata,3,1);
	setLayout(winLayout);
}

void OperazioniScudo::CalcolaUsabilita() {
	bool usabilita = scudoIstanza->VerificaUsabilita(*car);
	emit MostraRisultatoBooleano(usabilita);
}

void OperazioniScudo::CalcolaEquilibrio() {
	try {
		double equilibrio = scudoIstanza->Equilibrio(*car);
		emit MostraRisultatoNumerico(equilibrio);
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniScudo::CalcolaConfrontaDifesa() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Confronta Difesa con Scudo.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniScudo::CalcolaSomma() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza, costruire l'oggetto e cliccare operazione: Somma con Scudo.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniScudo::CalcolaSpezzaguardia() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Spezzaguardia.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniScudo::CalcolaParata() {
	try {
		double parata = scudoIstanza->Parata(*car);
		emit MostraRisultatoNumerico(parata);
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniScudo::connectSignalsOperazioniScudo(){
	connect(Spezzaguardia, SIGNAL(clicked()), this, SLOT(CalcolaSpezzaguardia()));
	connect(Parata, SIGNAL(clicked()), this, SLOT(CalcolaParata()));
};

