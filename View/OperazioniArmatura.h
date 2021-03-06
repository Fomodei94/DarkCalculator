#ifndef OPERAZIONI_ARMATURA
#define OPERAZIONI_ARMATURA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armatura.h"
#include "OperazioniArmamento.h"

class OperazioniArmatura : public OperazioniArmamento{
        Q_OBJECT
	private:
	QPushButton *Appesantisci,
					*Alleggerisci,
					*CottaDiMaglia,
					*Sopravvivenza;
	Armatura* armaturaIstanza;
	Caratteristiche* car;
	
	protected:
		void connectSignalsOperazioniArmatura();

	public:
		OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car);
	signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		void update();
  public slots:
		void CalcolaEquilibrio() override;
		void CalcolaUsabilita() override;
		void CalcolaConfrontaDifesa() override;
		void CalcolaSomma() override;
		void CalcolaAppesantisci();
		void CalcolaAlleggerisci();
		void CalcolaCottaDiMaglia();
		void CalcolaSopravvivenza();
};
#endif

