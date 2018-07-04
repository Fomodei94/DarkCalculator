#ifndef TABARMA_H
#define TABARMA_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include"../Model/Arma.h"
#include "OperazioniArma.h"

class TabArma : public QWidget
{
    Q_OBJECT

private:
		Arma* arma;
    Caratteristiche* car;
    OperazioniArma* operazioniArma;
    int playerNumber;
    QLabel* LblPeso;
    QDoubleSpinBox* peso;
    QLabel* LblUsura;
    QDoubleSpinBox* usura;
    QLabel* LblDannoBase;
    QDoubleSpinBox* DannoBase;
    QLabel* LblForzaRichiesta;
    QSpinBox* forzaRichiesta;
    QLabel* LblIntelligenzaRichiesta;
    QSpinBox* intelligenzaRichiesta;

 protected:
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
	void connectSignals();

public:
    TabArma(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* car);
    TabArma(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber);
    virtual void FinishInit();
    ~TabArma() = default;

signals:
	void MostraRisultatoNumerico2(double x);
	void MostraRisultatoBooleano2(bool x);
    
public slots:
	virtual void setPeso(double d);
	virtual void setUsura(double d);
	virtual void setDannoBase(double d);
	virtual void setForzaRichiesta(int i);
	virtual void setIntelligenzaRichiesta(int i);
};

#endif //  TABARMA_H
