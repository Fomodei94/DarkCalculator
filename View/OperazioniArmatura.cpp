#include "OperazioniArmatura.h"

OperazioniArmatura::OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car): OperazioniArmamento(parent), armaturaIstanza(armatura), car(car){
	label->setText("<h4>Operazioni Armatura </h4>");
	Appesantisci = new QPushButton("Appesantisci", this);
	Alleggerisci = new QPushButton("Alleggerisci", this);
	CottaDiMaglia = new QPushButton("Cotta di Maglia", this);
	Sopravvivenza = new QPushButton("Sopravvivenza", this);
	connectSignalsOperazioniProprie();
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
	try {
		double equilibrio = armaturaIstanza->Equilibrio(*car);
		emit MostraRisultatoNumerico(equilibrio);
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniArmatura::CalcolaConfrontaDifesa() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Confronta Difesa con Armatura.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmatura::CalcolaSomma() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza, costruire l'oggetto e cliccare operazione: Somma con Armatura.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmatura::CalcolaAppesantisci() {
	armaturaIstanza->Appesantisci();
	//emit   FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmatura::CalcolaAlleggerisci() {
	armaturaIstanza->Alleggerisci();
	//emit   FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmatura::CalcolaCottaDiMaglia() {
	armaturaIstanza->CottaDiMaglia();
	//emit   FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmatura::CalcolaSopravvivenza() {
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza, costruire l'oggetto e cliccare operazione: Sopravvivenza.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmatura::connectSignalsOperazioniProprie(){
	connect(Appesantisci, SIGNAL(clicked()), this, SLOT(CalcolaAppesantisci()));
	connect(Alleggerisci, SIGNAL(clicked()), this, SLOT(CalcolaAlleggerisci()));
	connect(CottaDiMaglia, SIGNAL(clicked()), this, SLOT(CalcolaCottaDiMaglia()));
	connect(Sopravvivenza, SIGNAL(clicked()), this, SLOT(CalcolaSopravvivenza()));
};
