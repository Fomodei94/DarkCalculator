#ifndef OPERAZIONI_ARMATURA
#define OPERAZIONI_ARMATURA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armatura.h"

class OperazioniArmatura: public QWidget{
        Q_OBJECT
	private:
	QPushButton *VerificaUsabilita,
					*Equilibrio,
					*Appesantisci,
					*Alleggerisci,
					*CottaDiMaglia,
					*Sopravvivenza,
					*ConfrontaDifesa;
	QLabel* label;
	QGridLayout* winLayout;
  Armatura* armaturaIstanza;
  Caratteristiche* car;
	public:
		OperazioniArmatura(QWidget* parent, Armatura* armatura, Caratteristiche* car);
  signals:
		void MostraRisultatoNumerico(double x);
  public slots:
		void CalcolaEquilibrio();
		void CalcolaUsabilita();
};
#endif

