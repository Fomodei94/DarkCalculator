#ifndef OPERAZIONI_ARMAMENTO
#define OPERAZIONI_ARMAMENTO
#include <QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armamento.h"

class OperazioniArmamento: public QWidget{
  Q_OBJECT
	private:
		QPushButton *Equilibrio,
							 *VerificaUsabilita,
							 *ConfrontaDifesa,
							 *Somma;
		Armamento* armamentoIstanza;
		Caratteristiche* car;
	
	protected:
		QGridLayout* winLayout;
		void connectSignalsOperazioni();
		QLabel* label;
  
	public:
		OperazioniArmamento(QWidget* parent = nullptr, Armamento* armamento = nullptr, Caratteristiche* car=nullptr);
	
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		
  public slots:
		virtual void CalcolaEquilibrio();
		virtual void CalcolaUsabilita();
		virtual void CalcolaConfrontaDifesa();
		virtual void CalcolaSomma();
};
#endif
