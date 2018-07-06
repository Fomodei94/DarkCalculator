#include "OperazioniArmaP2.h"

OperazioniArmaP2::OperazioniArmaP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): QWidget(parent), equipMap(equipMap), carP1(carP1), carP2(carP2){
  arma = dynamic_cast<Arma*>( equipMap->find("ArmaP2")->second );
	label = new QLabel("<h4>Operazioni Arma P2</h4>", this);
	ConfrontaConArma = new QPushButton("Confronta Danno con Arma", this);
	ConfrontaConArmaFisica = new QPushButton("Confronta Danno con Arma Fisica", this);
	ConfrontaConArmaMagica = new QPushButton("Confronta Danno con Arma Magica", this);
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
	winLayout->addWidget(SommaConArma,1,1);
	winLayout->addWidget(ConfrontaConArmaMagica,2,0);
	winLayout->addWidget(SommaConArmaMagica,2,1);
	winLayout->addWidget(ConfrontaConArmaFisica, 3,0);
	winLayout->addWidget(SommaConArmaFisica,3,1);
	winLayout->addWidget(Frantuma,4,0);
	winLayout->addWidget(Sopravvivenza,4,1);
	winLayout->addWidget(HyperArmor,5,0);
	winLayout->addWidget(SpezzaGuardia,5,1);
	setLayout(winLayout);
}

void OperazioniArmaP2::CalcolaConfrontaConArma(){
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, arma);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::CalcolaConfrontaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, arma);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}


void OperazioniArmaP2::CalcolaConfrontaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, arma);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::CalcolaSommaConArma(){
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
	double risultato = inv->operator+(*arma);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaP2::CalcolaSommaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	double risultato = inv->operator+(*arma);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaP2::CalcolaSommaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
	double risultato = inv->operator+(*arma);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaP2::CalcolaFrantuma(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try
	{
		double risultato = inv->Frantuma(*carP1, arma);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::CalcolaSopravvivenza(){
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	try
	{
		int risultato = inv->Sopravvivenza(*carP1, arma, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::CalcolaHyperArmor(){
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	try
	{
		double risultato = inv->HyperArmor(*carP1, arma);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::CalcolaSpezzaGuardia(){
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
	try
	{
		int risultato = inv->SpezzaGuardia(*carP1, arma, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaP2::connectSignalsOperazioni(){
	connect(ConfrontaConArma, SIGNAL(clicked()), this, SLOT(CalcolaConfrontaConArma()));
	connect(ConfrontaConArmaFisica, SIGNAL(clicked()), this, SLOT(CalcolaConfrontaConArmaFisica()));
	connect(ConfrontaConArmaMagica, SIGNAL(clicked()), this, SLOT(CalcolaConfrontaConArmaMagica()));
	connect(SommaConArma, SIGNAL(clicked()), this, SLOT(CalcolaSommaConArma()));
	connect(SommaConArmaFisica, SIGNAL(clicked()), this, SLOT(CalcolaSommaConArmaFisica()));
	connect(SommaConArmaMagica, SIGNAL(clicked()), this, SLOT(CalcolaSommaConArmaMagica()));
	connect(Frantuma, SIGNAL(clicked()), this, SLOT(CalcolaFrantuma()));
	connect(Sopravvivenza, SIGNAL(clicked()), this, SLOT(CalcolaSopravvivenza()));
	connect(HyperArmor, SIGNAL(clicked()), this, SLOT(CalcolaHyperArmor()));
	connect(SpezzaGuardia, SIGNAL(clicked()), this, SLOT(CalcolaSpezzaGuardia()));
}
