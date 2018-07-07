#ifndef TABSCUDO_H
#define TABSCUDO_H

#include "../Model/Scudo.h"
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include "OperazioniScudo.h"

class TabScudo: public QWidget{
	Q_OBJECT
	private:
		Scudo* scudo;
		QLabel  	*LblPeso,
						*LblUsura,
						*LblDifesa,
						*LblVigoreRichiesto,
						*LblStabilita,
						*LblAssorbMagico,
						*LblAssorbFisico,
						*LblScalingVigore;
		QDoubleSpinBox *peso,
									*usura,
									*Difesa,
									*AssorbMagico,
									*AssorbFisico;
		QSpinBox *vigoreRichiesto,
						*Stabilita;
		QComboBox *ScalingVigore;
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
	OperazioniScudo* operazioniScudo;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
	int playerNumber;

	protected:
		void connectSignalsScudo();

	public:
		TabScudo(QWidget* parent=nullptr, std::map<std::string, Equipaggiamento*>* equipMap=nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		void FinishInit();
	signals:
		void MostraRisultatoNumerico2(double x);
		void MostraRisultatoBooleano2(bool x);
	public slots:
		void setPeso(double d);
		void setUsura(double d);
		void setDifesa(double d);
		void setVigoreRichiesto(int i);
		void setStabilita(int i);
		void setAssorbMagico(double d);
		void setAssorbFisico(double d);
		void setScalingVigore(int i);
};
#endif


