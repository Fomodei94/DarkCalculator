#ifndef TABARMAFISICA_H
#define TABARMAFISICA_H
#include "TabArma.h"
#include "../Model/ArmaFisica.h"
#include <QLabel>
#include <QComboBox>
#include "OperazioniArmaFisica.h"
#include<QString>

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
		OperazioniArmaFisica* operazioniArmaFisica;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
		int playerNumber;
	protected:
		void connectSignalsArmaFisica();
	public:
		TabArmaFisica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		virtual void FinishInit() override;
	signals:
		void MostraRisultatoNumerico2(double x);
		void MostraRisultatoBooleano2(bool x);
	public slots:
		virtual void setPeso(double d) override;
		virtual void setUsura(double d) override;
		virtual void setDannoBase(double d) override;
		virtual void setForzaRichiesta(int i) override;
		virtual void setIntelligenzaRichiesta(int i) override;
		void setTipoDanno(int i);
		void setScalingForza(int i);
		void setScalingDestrezza(int i);
                void update();
};
#endif
