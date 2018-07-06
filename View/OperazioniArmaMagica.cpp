#include "OperazioniArmaMagica.h"

OperazioniArmaMagica::OperazioniArmaMagica(QWidget* parent, ArmaMagica* arma, Caratteristiche* car): OperazioniArma(parent), armaMagicaIstanza(arma), car(car){
	label->setText("<h4>Operazioni Arma Magica</h4>");
	Incanta = new QPushButton("Incanta", this);
	Infuoca = new QPushButton("Infuoca", this);
	Benedici = new QPushButton("Benedici", this);
	Maledici = new QPushButton("Maledici", this);
	ArteMistica = new QPushButton("Arte Mistica", this);
	connectSignalsOperazioniProprie();
	winLayout->addWidget(Incanta,3,1);
	winLayout->addWidget(Infuoca,4,0);
	winLayout->addWidget(Benedici,4,1);
	winLayout->addWidget(Maledici,5,0);
	winLayout->addWidget(ArteMistica,5,1);
	setLayout(winLayout);
}

void OperazioniArmaMagica::CalcolaDannoEffettivo(){
	try
	{
		double effettivo = armaMagicaIstanza->DannoEffettivo(*car);
		emit MostraRisultatoNumerico(effettivo);
	}
  catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniArmaMagica::CalcolaEfficacia(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Armamento, Armatura oppure Scudo a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Efficacia con Arma Magica.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaMagica::CalcolaUsabilita(){
	try
	{
		bool usabilita = armaMagicaIstanza->VerificaUsabilita(*car);
		emit MostraRisultatoBooleano(usabilita);
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "ATTENZIONE AI DANNI PERCENTUALI", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniArmaMagica::CalcolaConfronto(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza. Costruire l'oggetto e cliccare operazione: Confronta Danno con Arma Magica.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaMagica::CalcolaSomma(){
	QMessageBox* msg = new QMessageBox(QMessageBox::Information, "GUIDA PER L'OPERAZIONE", "Spostarsi nella sezione di destra, selezionare tab Arma, Arma Fisica oppure Arma Magica a seconda della preferenza, costruire l'oggetto e cliccare operazione: Somma con Arma Magica.", QMessageBox::Ok, this);
	msg->show();
}

void OperazioniArmaMagica::EseguiIncanta(){
	armaMagicaIstanza->Incanta();
	emit update();
}

void OperazioniArmaMagica::EseguiInfuoca(){
	armaMagicaIstanza->Infuoca();
	emit update();
}

void OperazioniArmaMagica::EseguiBenedici(){
	armaMagicaIstanza->Benedici();
	emit update();
}

void OperazioniArmaMagica::EseguiMaledici(){
	armaMagicaIstanza->Maledici();
	emit update();
}

void OperazioniArmaMagica::CalcolaArteMistica(){
	try
	{
		double ret = armaMagicaIstanza->ArteMistica(*car);
		emit MostraRisultatoNumerico(ret);
		emit update();
	}
	catch(const char*& exc){
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
		msg->show();
	}
}

void OperazioniArmaMagica::connectSignalsOperazioniProprie(){
	connect(Incanta, SIGNAL(clicked()), this, SLOT(EseguiIncanta()));
	connect(Infuoca, SIGNAL(clicked()), this, SLOT(EseguiInfuoca()));
	connect(Benedici, SIGNAL(clicked()), this, SLOT(EseguiBenedici()));
	connect(Maledici, SIGNAL(clicked()), this, SLOT(EseguiMaledici()));
	connect(ArteMistica, SIGNAL(clicked()), this, SLOT(CalcolaArteMistica()));
}

