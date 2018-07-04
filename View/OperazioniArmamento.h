#ifndef OPERAZIONI_ARMAMENTO
#define OPERAZIONI_ARMAMENTO
#include<QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Armamento.h"

class OperazioniArmamento: public QWidget{
  Q_OBJECT
	private:
		QPushButton *Equilibrio,
							 *VerificaUsabilita;
		QLabel* label;
		QGridLayout* winLayout;
		Armamento* armamentoIstanza;
		Caratteristiche* car;
	
	protected:
		void connectSignalsOperazioni();
  
	public:
		OperazioniArmamento(QWidget* parent = nullptr, Armamento* armamento = nullptr, Caratteristiche* car=nullptr);
	
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		
  public slots:
		virtual void CalcolaEquilibrio();
		virtual void CalcolaUsabilita();
};
#endif