#include "OperazioniArmamentoP2.h"

OperazioniArmamentoP2::OperazioniArmamentoP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): QWidget(parent), equipMap(equipMap), carP1(carP1), carP2(carP2){
	armamento = dynamic_cast<Armamento*>( equipMap->find("ArmamentoP2")->second );
	label = new QLabel("<h4>Operazioni Armamento P2</h4>", this);
	EfficaciaConArma = new QPushButton("Efficacia con Arma", this);
	EfficaciaConArmaFisica = new QPushButton("Efficacia con Arma Fisica", this);
	EfficaciaConArmaMagica = new QPushButton("Efficacia con Arma Magica", this);
	SommaConArmamento = new QPushButton("Somma Difesa Con Armamento", this);
	SommaConArmatura = new QPushButton("Somma Difesa con Armatura", this);
	SommaConScudo = new QPushButton("Somma Difesa con Scudo", this);
	Frantuma = new QPushButton("Frantuma", this);
	ConfrontaConArmamento = new QPushButton("Confronta con Armamento", this);
	ConfrontaConArmatura = new QPushButton("Confronta con Armatura", this);
	ConfrontaConScudo = new QPushButton("Confronta con Scudo", this);
	connectSignalsOperazioni();
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(EfficaciaConArma, 1,0);
	winLayout->addWidget(EfficaciaConArmaFisica,1,1);
	winLayout->addWidget(EfficaciaConArmaMagica,2,0);
	winLayout->addWidget(SommaConArmamento,2,1);
	winLayout->addWidget(SommaConArmatura, 3,0);
	winLayout->addWidget(SommaConScudo,3,1);
	winLayout->addWidget(Frantuma,4,0);
	winLayout->addWidget(ConfrontaConArmamento,4,1);
	winLayout->addWidget(ConfrontaConArmatura,5,0);
	winLayout->addWidget(ConfrontaConScudo,5,1);
	setLayout(winLayout);
}

void OperazioniArmamentoP2::CalcolaConfrontaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armamento);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaConfrontaConArmatura {
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armamento);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaConfrontaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armamento);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaEfficaciaConArma {
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armamento);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaEfficaciaConArmaFisica {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armamento);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaEfficaciaConArmaMagica {
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armamento);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaFrantuma {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Frantuma(*carP1, armamento);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmamentoP2::CalcolaSommaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
	double risultato = inv->operator+(*armamento);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmamentoP2::CalcolaSommaConArmatura{
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	double risultato = inv->operator+(*armamento);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmamentoP2::CalcolaSommaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
	double risultato = inv->operator+(*armamento);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmamentoP2::connectSignalsOperazioni(){
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
