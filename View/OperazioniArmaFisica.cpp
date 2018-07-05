#include "OperazioniArmaFisica.h"

OperazioniArmaFisica::OperazioniArmaFisica(QWidget* parent, ArmaFisica* arma, Caratteristiche* car): OperazioniArma(parent), armaFisicaIstanza(arma), car(car){
	label->setText("<h4>Operazioni Arma Fisica</h4>");
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
	try
	{
		double effettivo = armaFisicaIstanza->DannoEffettivo(*car);
		emit MostraRisultatoNumerico(effettivo);
	}
  catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniArmaFisica::CalcolaEfficacia(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Efficacia con ArmaFisica.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaFisica::CalcolaUsabilita(){
	bool usabilita = armaFisicaIstanza->VerificaUsabilita(*car);
  emit MostraRisultatoBooleano(usabilita);
}

void OperazioniArmaFisica::CalcolaConfronto(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Confronta Danno con Arma.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaFisica::CalcolaSomma(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza, costruire l'oggetto e cliccare operazione: Somma con Arma.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaFisica::EseguiRaffina(){
	armaFisicaIstanza->Raffina();
	//FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmaFisica::EseguiRiforgia(){
	armaFisicaIstanza->Riforgia();
	//FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmaFisica::EseguiCristallizza(){
	armaFisicaIstanza->Cristallizza();
	//FUNZIONE PER AGGIORNARE GUI
}

void OperazioniArmaFisica::CalcolaFrantuma(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica Arma Magica, Armamento, Armatura oppure Scudo, a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Frantuma.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaFisica::connectSignalsOperazioniProprie(){
	connect(Raffina, SIGNAL(clicked()), this, SLOT(EseguiRaffina()));
	connect(Riforgia, SIGNAL(clicked()), this, SLOT(EseguiRiforgia()));
	connect(Cristallizza, SIGNAL(clicked()), this, SLOT(EseguiCristallizza()));
	connect(Frantuma, SIGNAL(clicked()), this, SLOT(CalcolaFrantuma()));
}
