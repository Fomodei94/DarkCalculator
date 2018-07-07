#ifndef TABARMAMENTO_H
#define TABARMAMENTO_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include "../Model/Armamento.h"
#include "OperazioniArmamento.h"
#include "OperazioniArmamentoP2.h"

class TabArmamento : public QWidget
{
    Q_OBJECT

private:
	Armamento* armamento;
    Caratteristiche* carP1;
	Caratteristiche* carP2;
    QWidget* operazioniArmamento;
    int playerNumber;
    QLabel* LblPeso;
    QDoubleSpinBox* peso;
    QLabel* LblUsura;
    QDoubleSpinBox* usura;
    QLabel* LblDifesa;
    QDoubleSpinBox* Difesa;
    QLabel* LblVigoreRichiesto;
    QSpinBox* vigoreRichiesto;
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
	void connectSignals();

public:
    TabArmamento(QWidget *parent=nullptr, std::map<std::string, Equipaggiamento*>* equipMap=nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
    void FinishInit();

signals:
	void MostraRisultatoNumerico2(double x);
	void MostraRisultatoBooleano2(bool x);

public slots:
	void setPeso(double d);
	void setUsura(double d);
	void setDifesa(double d);
	void setVigoreRichiesto(int i);
};

#endif //  TABARMAMENTO_H
