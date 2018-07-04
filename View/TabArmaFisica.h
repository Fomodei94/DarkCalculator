#ifndef TABARMAFISICA_H
#define TABARMAFISICA_H
#include "TabArma.h"
#include "../Model/ArmaFisica.h"
#include <QLabel>
#include <QComboBox>
#include "OperazioniArmaFisica.h"

class TabArmaFisica: public TabArma{
	Q_OBJECT
	private:
		ArmaFisica* armaFisica;
		QLabel *LblTipoDanno,
						*LblScalingForza,
						*LblScalingDestrezza;
		QComboBox *TipoDanno,
								*ScalingForza,
								*ScalingDestrezza;
		OperazioniArmaFisica* operazioni;
    Caratteristiche* car;
		int playerNumber;
	public:
		TabArmaFisica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* car=nullptr);
		virtual void FinishInit() override;
	signals:
		void MostraDannoEffettivo2(int x);
	public slots:
		virtual void setPeso(double d) override;
		virtual void setUsura(double d) override;
		virtual void setDannoBase(double d) override;
		virtual void setForzaRichiesta(int i) override;
		virtual void setIntelligenzaRichiesta(int i) override;
};
#endif
