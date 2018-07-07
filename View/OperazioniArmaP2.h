#ifndef OPERAZIONI_ARMAP2
#define OPERAZIONI_ARMAP2
#include<QMessageBox>
#include<QString>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Arma.h"
#include "../Model/ArmaFisica.h"
#include "../Model/ArmaMagica.h"
#include "../Model/Armatura.h"
#include "../Model/Scudo.h"
#include <map>

class OperazioniArmaP2: public QWidget{
  Q_OBJECT
	private:
		QPushButton *ConfrontaConArma,
					*ConfrontaConArmaFisica,
					*ConfrontaConArmaMagica,
					*SommaConArma,
					*SommaConArmaFisica,
					*SommaConArmaMagica,
					*Frantuma,
					*Sopravvivenza,
					*HyperArmor,
					*SpezzaGuardia;
		Caratteristiche* carP1;
		Caratteristiche* carP2;
    Arma* arma;

	protected:
		QLabel* label;
		void connectSignalsOperazioni();
		QGridLayout* winLayout;
		std::map<std::string, Equipaggiamento*>* equipMap;

	public:
		OperazioniArmaP2(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, Caratteristiche* carP1 = nullptr, Caratteristiche* carP2 = nullptr);

  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);

  public slots:
		virtual void CalcolaConfrontaConArma();
		virtual void CalcolaConfrontaConArmaFisica();
		virtual void CalcolaConfrontaConArmaMagica();
		virtual void CalcolaSommaConArma();
		virtual void CalcolaSommaConArmaFisica();
		virtual void CalcolaSommaConArmaMagica();
		virtual void CalcolaFrantuma();
		virtual void CalcolaSopravvivenza();
		virtual void CalcolaHyperArmor();
		virtual void CalcolaSpezzaGuardia();
};
#endif


