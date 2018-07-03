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
		QLabel *LblTipoDanno,
						*LblScalingForza,
						*LblScalingDestrezza;
		QComboBox *TipoDanno,
								*ScalingForza,
								*ScalingDestrezza;
		OperazioniArmaFisica* operazioni;
		int playerNumber;
	public:
		TabArmaFisica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1);
		virtual void FinishInit() override;
};
#endif
