#ifndef TABARMATURA_H
#define TABARMATURA_H
#include "TabArmamento.h"
#include "../Model/Armatura.h"
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include "OperazioniArmatura.h"

class TabArmatura: public TabArmamento{
	Q_OBJECT
	private:
		Armatura* armatura;
		QLabel  *LblDifMagia,
						*LblDifOscurita,
						*LblDifFuoco,
						*LblDifElettricita,
						*LblDifTaglio,
						*LblDifContundente,
						*LblDifAffondo;
		QDoubleSpinBox *DifMagia,
								*DifOscurita,
								*DifFuoco,
								*DifElettricita,
								*DifTaglio,
								*DifContundente,
								*DifAffondo;
	OperazioniArmatura* operazioniArmatura;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
	int playerNumber;
	public:
		TabArmatura(QWidget* parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2);
		virtual void FinishInit() override;
	signals:
		void MostraRisultatoNumerico2(double x);
	public slots:
		virtual void setPeso(double d) override;
		virtual void setUsura(double d) override;
		virtual void setDifesa(double d) override;
		virtual void setVigoreRichiesto(int i) override;
};
#endif

