#include "OperazioniScudoP2.h"

OperazioniScudoP2::OperazioniScudoP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): OperazioniArmamentoP2(parent, equipMap), carP1(carP1), carP2(carP2){
	scudoIstanza = dynamic_cast<Scudo*>(OperazioniArmamentoP2::equipMap->find("ScudoP2")->second );
	label->setText("<h4>Operazioni Scudo P2</h4>");
}

void OperazioniScudoP2::CalcolaConfrontaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, scudoIstanza);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaConfrontaConArmatura {
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, scudoIstanza);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaConfrontaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, scudoIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaEfficaciaConArma {
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, scudoIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaEfficaciaConArmaFisica {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, scudoIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaEfficaciaConArmaMagica {
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, scudoIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaFrantuma {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Frantuma(*carP1, scudoIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniScudoP2::CalcolaSommaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
	double risultato = inv->operator+(*scudoIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniScudoP2::CalcolaSommaConArmatura{
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	double risultato = inv->operator+(*scudoIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniScudoP2::CalcolaSommaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
	double risultato = inv->operator+(*scudoIstanza);
	emit MostraRisultatoNumerico(risultato);
}

