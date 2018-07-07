#ifndef OPERAZIONI_ARMAMENTOP2
#define OPERAZIONI_ARMAMENTOP2
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armamento.h"
#include "../Model/ArmaFisica.h"
#include "../Model/ArmaMagica.h"
#include "../Model/Armatura.h"
#include "../Model/Scudo.h"
#include <map>

class OperazioniArmamentoP2: public QWidget{
  Q_OBJECT
	private:
		QPushButton *EfficaciaConArma,
					*EfficaciaConArmaFisica,
					*EfficaciaConArmaMagica,
					*SommaConArmamento,
					*SommaConArmatura,
					*SommaConScudo,
					*Frantuma,
					*ConfrontaConArmamento,
					*ConfrontaConArmatura,
					*ConfrontaConScudo;
		std::map<std::string, Equipaggiamento*>* equipMap;
		Caratteristiche* carP1;
		Caratteristiche* carP2;
		Armamento* armamento;

	protected:
		QLabel* label;
		void connectSignalsOperazioni();
		QGridLayout* winLayout;

	public:
		OperazioniArmamentoP2(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, Caratteristiche* carP1 = nullptr, Caratteristiche* carP2 = nullptr);

  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);

  public slots:
		virtual void CalcolaConfrontaConArmamento();
		virtual void CalcolaConfrontaConArmatura();
		virtual void CalcolaConfrontaConScudo();
		virtual void CalcolaSommaConArmamento();
		virtual void CalcolaSommaConArmatura();
		virtual void CalcolaSommaConScudo();
		virtual void CalcolaFrantuma();
		virtual void CalcolaEfficaciaConArma();
		virtual void CalcolaEfficaciaConArmaFisica();
		virtual void CalcolaEfficaciaConArmaMagica();
};
#endif



