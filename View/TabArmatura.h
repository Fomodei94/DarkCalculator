#ifndef TABARMATURA_H
#define TABARMATURA_H

#include "../Model/Armatura.h"
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include "OperazioniArmatura.h"
#include "OperazioniArmaturaP2.h"

class TabArmatura: public QWidget {
	Q_OBJECT
	private:
		Armatura* armatura;
		QLabel  	*LblPeso,
						*LblUsura,
						*LblDifesa,
						*LblVigoreRichiesto,
						*LblDifMagia,
						*LblDifOscurita,
						*LblDifFuoco,
						*LblDifElettricita,
						*LblDifTaglio,
						*LblDifContundente,
						*LblDifAffondo;
		QDoubleSpinBox	*peso,
								*usura,
								*Difesa,
								*DifMagia,
								*DifOscurita,
								*DifFuoco,
								*DifElettricita,
								*DifTaglio,
								*DifContundente,
								*DifAffondo;
		QSpinBox* vigoreRichiesto;
		QGridLayout *winLayout;
		std::map<std::string, Equipaggiamento*>* equipMap;
		QWidget* operazioniArmatura;
		Caratteristiche* carP1;
		Caratteristiche* carP2;
		int playerNumber;
		void connectSignalsArmatura();

	public:
		TabArmatura(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber = 1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		void FinishInit();
		
	signals:
		void MostraRisultatoBooleano2(bool x);
		void MostraRisultatoNumerico2(double x);
		
	public slots:
		void setPeso(double d);
		void setUsura(double d);
		void setDifesa(double d);
		void setVigoreRichiesto(int i);
		void setDifMagia(double d);
		void setDifOscurita(double d);
		void setDifFuoco(double d);
		void setDifElettricita(double d);
		void setDifTaglio(double d);
		void setDifContundente(double d);
		void setDifAffondo(double d);
		void update();
};
#endif

