#include"OperazioniArmaFisicaP2.h"

OperazioniArmaFisicaP2::OperazioniArmaFisicaP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): OperazioniArmaP2(parent, equipMap), carP1(carP1), carP2(carP2){
	armaFisicaIstanza = dynamic_cast<ArmaFisica*>( equipMap->find("ArmaFisicaP2")->second );
	label->setText("<h4>Operazioni Arma Fisica P2</h4>");
}

void OperazioniArmaFisicaP2::CalcolaConfrontaConArma(){
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaFisicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaFisicaP2::CalcolaConfrontaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaFisicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}


void OperazioniArmaFisicaP2::CalcolaConfrontaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDanno(*carP1, armaFisicaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaFisicaP2::CalcolaSommaConArma(){
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
	double risultato = inv->operator+(*armaFisicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaFisicaP2::CalcolaSommaConArmaFisica(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	double risultato = inv->operator+(*armaFisicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaFisicaP2::CalcolaSommaConArmaMagica(){
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
	double risultato = inv->operator+(*armaFisicaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaFisicaP2::CalcolaFrantuma(){
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try
	{
		double risultato = inv->Frantuma(*carP1, armaFisicaIstanza);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaFisicaP2::CalcolaSopravvivenza(){
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	try
	{
		int risultato = inv->Sopravvivenza(*carP1, armaFisicaIstanza, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaFisicaP2::CalcolaHyperArmor(){
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	try
	{
		double risultato = inv->HyperArmor(*carP1, armaFisicaIstanza);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaFisicaP2::CalcolaSpezzaGuardia(){
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
	try
	{
		int risultato = inv->SpezzaGuardia(*carP1, armaFisicaIstanza, *carP2);
    emit MostraRisultatoNumerico(risultato);
	}
	catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

