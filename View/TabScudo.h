#ifndef TABSCUDO_H
#define TABSCUDO_H
#include "TabArmamento.h"
#include "../Model/Scudo.h"
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
//#include "OperazioniScudo.h"

class TabScudo: public TabArmamento{
	Q_OBJECT
	private:
		Scudo* scudo;
		QLabel  *LblStabilita,
						*LblAssorbMagico,
						*LblAssorbFisico,
						*LblScalingVigore;
		QDoubleSpinBox *AssorbMagico,
									*AssorbFisico;
		QSpinBox * Stabilita;
		QComboBox *ScalingVigore;
	//OperazioniScudo* operazioniScudo;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
	int playerNumber;
	public:
		TabScudo(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2);
		void FinishInit() override;
	signals:
		void MostraRisultatoNumerico2(double x);
		void MostraRisultatoBooleano2(bool x);
	public slots:
		void setPeso(double d) override;
		void setUsura(double d) override;
		void setDifesa(double d) override;
		void setVigoreRichiesto(int i) override;
};
#endif


