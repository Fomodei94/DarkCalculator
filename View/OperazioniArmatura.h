#ifndef OPERAZIONI_ARMATURA
#define OPERAZIONI_ARMATURA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armatura.h"

class OperazioniArmatura: public OperazioniArmamento{
        Q_OBJECT
	private:
	QPushButton *Appesantisci,
					*Alleggerisci,
					*CottaDiMaglia,
					*Sopravvivenza,
					*ConfrontaDifesa;
	
	Armatura* armaturaIstanza;
	Caratteristiche* car;
	public:
		OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car);
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(double x);
  public slots:
		void CalcolaEquilibrio() override;
		void CalcolaUsabilita() override;
};
#endif

