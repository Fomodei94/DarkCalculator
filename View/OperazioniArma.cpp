#include "OperazioniArma.h"

OperazioniArma::OperazioniArma(QWidget* parent, Arma* arma, Caratteristiche* car): QWidget(parent), armaIstanza(arma), car(car){
	label = new QLabel("<h4>Operazioni Arma </h4>", this);
	DannoEffettivo = new QPushButton("Danno Effettivo", this);
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


void OperazioniArma::CalcolaDannoEffettivo(){
	double effettivo = armaIstanza->DannoEffettivo(*car);
  emit MostraRisultatoNumerico(effettivo);
}

void OperazioniArma::CalcolaEfficacia(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza, costruire l'oggetto e clillare operazione: Efficacia con Arma.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArma::CalcolaUsabilita(){
	bool usabilita = armaIstanza->VerificaUsabilita(*car);
  emit MostraRisultatoBooleano(usabilita);
}

void OperazioniArma::connectSignalsOperazioni(){
	connect(DannoEffettivo, SIGNAL(clicked()), this, SLOT(CalcolaDannoEffettivo()));
	connect(Efficacia, SIGNAL(clicked()), this, SLOT(CalcolaEfficacia()));
	connect(VerificaUsabilita, SIGNAL(clicked()), this, SLOT(CalcolaUsabilita()));
};

