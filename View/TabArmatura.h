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

	protected:
		void connectSignalsArmatura();

	public:
		TabArmatura(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber = 1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		void FinishInit() override;
                void update();
	signals:
		void MostraRisultatoBooleano2(bool x);
		void MostraRisultatoNumerico2(double x);
	public slots:
		virtual void setPeso(double d) override;
		virtual void setUsura(double d) override;
		virtual void setDifesa(double d) override;
		virtual void setVigoreRichiesto(int i) override;
		void setDifMagia(double d);
		void setDifOscurita(double d);
		void setDifFuoco(double d);
		void setDifElettricita(double d);
		void setDifTaglio(double d);
		void setDifContundente(double d);
		void setDifAffondo(double d);
};
#endif

