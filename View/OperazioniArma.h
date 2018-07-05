#ifndef OPERAZIONI_ARMA
#define OPERAZIONI_ARMA
#include<QMessageBox>
#include<QString>
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
					*VerificaUsabilita,
					*ConfrontaDanno,
					*Somma;
		QLabel* label;
		QGridLayout* winLayout;
		Arma* armaIstanza;
		Caratteristiche* car;
	
	protected:
		void connectSignalsOperazioni();
  
	public:
		OperazioniArma(QWidget* parent = nullptr, Arma* arma = nullptr, Caratteristiche* car=nullptr);
	
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		
  public slots:
		virtual void CalcolaDannoEffettivo();
		virtual void CalcolaEfficacia();
		virtual void CalcolaUsabilita();
		virtual void CalcolaConfronto();
		virtual void CalcolaSomma();
};
#endif

