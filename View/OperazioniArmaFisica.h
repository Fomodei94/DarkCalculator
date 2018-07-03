#ifndef OPERAZIONI_ARMAFISICA
#define OPERAZIONI_ARMAFISICA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/ArmaFisica.h"

class OperazioniArmaFisica: public QWidget{
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
	public:
		OperazioniArmaFisica(QWidget* parent = nullptr, ArmaFisica* arma = nullptr);
};
#endif
