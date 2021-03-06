#ifndef OPERAZIONI_ARMAFISICA
#define OPERAZIONI_ARMAFISICA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/ArmaFisica.h"
#include"OperazioniArma.h"

class OperazioniArmaFisica: public OperazioniArma{
        Q_OBJECT
	private:
	QPushButton *Raffina,
							*Frantuma,
							*Cristallizza,
							*Riforgia;
		ArmaFisica* armaFisicaIstanza;
		Caratteristiche* car;
  protected:
		void connectSignalsOperazioniProprie();

	public:
		OperazioniArmaFisica(QWidget* parent = nullptr, ArmaFisica* arma = nullptr, Caratteristiche* car=nullptr);

  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
    void update();
  public slots:
		void CalcolaDannoEffettivo() override;
		void CalcolaEfficacia() override;
		void CalcolaUsabilita() override;
		void CalcolaConfronto() override;
		void CalcolaSomma() override;
		void EseguiRaffina();
		void EseguiCristallizza();
		void EseguiRiforgia();
		void CalcolaFrantuma();
};
#endif
