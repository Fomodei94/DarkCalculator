#include "OperazioniArmaturaP2.h"

OperazioniArmaturaP2::OperazioniArmaturaP2(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, Caratteristiche* carP1, Caratteristiche* carP2): OperazioniArmamentoP2(parent, equipMap), carP1(carP1), carP2(carP2){
	armaturaIstanza = dynamic_cast<Armatura*>(OperazioniArmamentoP2::equipMap->find("ArmaturaP2")->second );
	label->setText("<h4>Operazioni Armatura P2</h4>");
}

void OperazioniArmaturaP2::CalcolaConfrontaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armaturaIstanza);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaConfrontaConArmatura {
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armaturaIstanza);
		emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaConfrontaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
  try 
  {
		double risultato = inv->ConfrontaDifesa(*carP1, armaturaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaEfficaciaConArma {
	Arma* inv = dynamic_cast<Arma*>(equipMap->find("ArmaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armaturaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaEfficaciaConArmaFisica {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armaturaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaEfficaciaConArmaMagica {
	ArmaMagica* inv = dynamic_cast<ArmaMagica*>(equipMap->find("ArmaMagicaP1")->second);
	try 
  {
		double risultato = inv->Efficacia(*carP1, armaturaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaFrantuma {
	ArmaFisica* inv = dynamic_cast<ArmaFisica*>(equipMap->find("ArmaFisicaP1")->second);
	try 
  {
		double risultato = inv->Frantuma(*carP1, armaturaIstanza);
    emit MostraRisultatoNumerico(risultato);
  }
  catch(const char*& exc) {
		QMessageBox* msg = new QMessageBox(QMessageBox::Warning, "OPERAZIONE NON VALIDA", QString::fromStdString(exc), QMessageBox::Ok, this);
    msg->show();
	}
}

void OperazioniArmaturaP2::CalcolaSommaConArmamento {
	Armamento* inv = dynamic_cast<Armamento*>(equipMap->find("ArmamentoP1")->second);
	double risultato = inv->operator+(*armaturaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaturaP2::CalcolaSommaConArmatura{
	Armatura* inv = dynamic_cast<Armatura*>(equipMap->find("ArmaturaP1")->second);
	double risultato = inv->operator+(*armaturaIstanza);
	emit MostraRisultatoNumerico(risultato);
}

void OperazioniArmaturaP2::CalcolaSommaConScudo {
	Scudo* inv = dynamic_cast<Scudo*>(equipMap->find("ScudoP1")->second);
	double risultato = inv->operator+(*armaturaIstanza);
	emit MostraRisultatoNumerico(risultato);
}
