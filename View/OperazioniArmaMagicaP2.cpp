#include"OperazioniArmaMagicaP2.h"

OperazioniArmaMagicaP2::OperazioniArmaMagicaP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): OperazioniArmaP2(parent, equipMap), carP1(carP1), carP2(carP2){
	armaMagicaIstanza = dynamic_cast<ArmaMagica*>(OperazioniArmaP2::equipMap->find("ArmaMagicaP2")->second );
	label->setText("<h4>Operazioni Arma Magica P2</h4>");
}

void OperazioniArmaMagicaP2::CalcolaConfrontaConArma(){
	Arma* inv = dynamic_cast<Arma*>(OperazioniArmaP2::equipMap->find("ArmaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaMagicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaMagicaP2::CalcolaConfrontaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(OperazioniArmaP2::equipMap->find("ArmaFisicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaMagicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}


void OperazioniArmaMagicaP2::CalcolaConfrontaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(OperazioniArmaP2::equipMap->find("ArmaMagicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaMagicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaMagicaP2::CalcolaSommaConArma(){
	Arma* inv = dynamic_cast<Arma*>(OperazioniArmaP2::equipMap->find("ArmaP1")->second);
	double risultato = inv->operator+(*armaMagicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaMagicaP2::CalcolaSommaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(OperazioniArmaP2::equipMap->find("ArmaFisicaP1")->second);
	double risultato = inv->operator+(*armaMagicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaMagicaP2::CalcolaSommaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(OperazioniArmaP2::equipMap->find("ArmaMagicaP1")->second);
	double risultato = inv->operator+(*armaMagicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaMagicaP2::CalcolaFrantuma(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(OperazioniArmaP2::equipMap->find("ArmaFisicaP1")->second);
	try
	{
		double risultato = inv->Frantuma(*carP1, armaMagicaIstanza);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaMagicaP2::CalcolaSopravvivenza(){
	Armatura* inv = dynamic_cast<Armatura*>(OperazioniArmaP2::equipMap->find("ArmaturaP1")->second);
	try
	{
		int risultato = inv->Sopravvivenza(*carP1, armaMagicaIstanza, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaMagicaP2::CalcolaHyperArmor(){
	Armatura* inv = dynamic_cast<Armatura*>(OperazioniArmaP2::equipMap->find("ArmaturaP1")->second);
	try
	{
		double risultato = inv->HyperArmor(*carP1, armaMagicaIstanza);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaMagicaP2::CalcolaSpezzaGuardia(){
	Scudo* inv = dynamic_cast<Scudo*>(OperazioniArmaP2::equipMap->find("ScudoP1")->second);
	try
	{
		int risultato = inv->SpezzaGuardia(*carP1, armaMagicaIstanza, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}


