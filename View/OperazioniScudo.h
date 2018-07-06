#ifndef OPERAZIONI_SCUDO
#define OPERAZIONI_SCUDO
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Scudo.h"
#include "OperazioniArmamento.h"

class OperazioniScudo : public OperazioniArmamento{
        Q_OBJECT
	private:
	QPushButton *Spezzaguardia,
					*Parata;
	Scudo* scudoIstanza;
	Caratteristiche* car;
	
	protected:
		void connectSignalsOperazioniScudo();

	public:
		OperazioniScudo(QWidget* parent, Scudo* scudo, Caratteristiche* car);
	signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
  public slots:
		void CalcolaEquilibrio() override;
		void CalcolaUsabilita() override;
		void CalcolaConfrontaDifesa() override;
		void CalcolaSomma() override;
		void CalcolaSpezzaguardia();
		void CalcolaParata();
};
#endif

