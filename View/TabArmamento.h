#ifndef TABARMAMENTO_H
#define TABARMAMENTO_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include"../Model/Armamento.h"
#include "OperazioniArmamento.h"

class TabArmamento : public QWidget
{
    Q_OBJECT

private:
	Armamento* armamento;
    Caratteristiche* carP1;
	Caratteristiche* carP2;
    OperazioniArmamento* operazioniArmamento;
    int playerNumber;
    QLabel* LblPeso;
    QDoubleSpinBox* peso;
    QLabel* LblUsura;
    QDoubleSpinBox* usura;
    QLabel* LblDifesa;
    QDoubleSpinBox* Difesa;
    QLabel* LblVigoreRichiesto;
    QSpinBox* vigoreRichiesto;

 protected:
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
	void connectSignals();

public:
    TabArmamento(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2);
    TabArmamento(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber);
    virtual void FinishInit();
    ~TabArmamento() = default;
    
signals:
	void MostraRisultatoNumerico2(double x);
	void MostraRisultatoBooleano2(bool x);

public slots:
	virtual void setPeso(double d);
	virtual void setUsura(double d);
	virtual void setDifesa(double d);
	virtual void setVigoreRichiesto(int i);
};

#endif //  TABARMA_H
