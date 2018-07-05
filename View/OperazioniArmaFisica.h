#ifndef OPERAZIONI_ARMAFISICA
#define OPERAZIONI_ARMAFISICA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/ArmaFisica.h"

class OperazioniArmaFisica: public QWidget{
        Q_OBJECT
	private:
	QPushButton *DannoEffettivo,
					*Efficacia,
					*VerificaUsabilita,
					*Raffina,
					*Frantuma,
					*Cristallizza,
					*Riforgia;
	QLabel* label;
	QGridLayout* winLayout;
  ArmaFisica* armaIstanza;
  Caratteristiche* car;
	public:
		OperazioniArmaFisica(QWidget* parent = nullptr, ArmaFisica* arma = nullptr, Caratteristiche* car=nullptr);
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
  public slots:
		void CalcolaDannoEffettivo();
};
#endif
