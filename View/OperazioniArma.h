#ifndef OPERAZIONI_ARMA
#define OPERAZIONI_ARMA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/Arma.h"

class OperazioniArma: public QWidget{
  Q_OBJECT
	private:
		QPushButton *DannoEffettivo,
					*Efficacia,
					*VerificaUsabilita;
		QLabel* label;
		QGridLayout* winLayout;
		Arma* armaIstanza;
		Caratteristiche* car;
	
	protected:
		void connectSignalsOperazioni();
  
	public:
		OperazioniArma(QWidget* parent = nullptr, Arma* arma = nullptr, Caratteristiche* car=nullptr);
	/*	
  signals:
		virtual void MostraDannoEffettivo(double x);
		
  public slots:
		virtual void CalcolaDannoEffettivo();*/
};
#endif

